//libraries needed for gps tracker and blynk appp
#include <BlynkSimpleEsp8266.h>
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RX = 4, TX = 5;   // gpio pins of esp for gps 
static const uint32_t GPSBaud = 9600; //baud rate of gps

TinyGPSPlus GPS; // TinyGPS++ object
WidgetMap Map(V15);  // in blynk app virtual pin v15 is defined for map

SoftwareSerial gps(RX, TX);  // Serial connection to the GPS device

BlynkTimer clocktime; 

float speeed;       //store the speed
float satelliites;      //store no. of satellites response
String bear;  // store orientation or direction of GPS

char AUTH[] = "i_d-Gt0_fB7wjMeedKWBLD8leyHFj8h4";              // authentication key
char SSid[] = "Neehit";                                  // network (HotSpot or Router name)
char PASS[] = "7986915271";                                  // Password




//unsigned int move_index;         // moving index, to be used later
unsigned int move_index = 1;       // fixed location for now
  

void setup()
{
  Serial.begin(115200);
  Serial.println();
  gps.begin(GPSBaud);
  Blynk.begin(AUTH,SSid,PASS);
  clocktime.setInterval(5000L, check); // every 5s check if GPS is connected, only really needs to be done once
}

void check(){
  if (GPS.charsProcessed() < 10)
  {
    Serial.println(F("No GPS detected: check wiring."));
      Blynk.virtualWrite(V13, "GPS ERROR");  // Value Display widget on V13 if GPS not detected
  }
}

void loop()
{
 
    while (gps.available() > 0) 
    {
      // sketch displays information every time a new sentence is correctly encoded.
      if (GPS.encode(gps.read()))
        maincode();
  }
  Blynk.run();
  clocktime.run();
}

void maincode()
{ 

  if (GPS.location.isValid() ) 
  {
    float longitude = (GPS.location.lng()); 
    float latitude = (GPS.location.lat());     //latitude and longitude value
    Serial.print("LAT:  ");
    Serial.println(latitude, 6);  // float to x decimal places
    Serial.print("LONG: ");
    Serial.println(longitude, 6);
    Blynk.virtualWrite(V10, String(latitude, 6));   //sending data to blynk app
    Blynk.virtualWrite(V11, String(longitude, 6));  
    Map.location(move_index, latitude, longitude, "GPS_Location");// plotting location on map
    speeed = GPS.speed.kmph();               //get speed
       Blynk.virtualWrite(V12, speeed);
       
       satelliites = GPS.satellites.value();    //get number of satellites
       Blynk.virtualWrite(V13, satelliites);

       bear = TinyGPSPlus::cardinal(GPS.course.value()); // get the direction
       Blynk.virtualWrite(V14, bear);               
      
    
  }
  

  Serial.println();
}
