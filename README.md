<----Title of the project---->

Smart watch for tracking people in isolation

<----Description-->

Smart watch is basically a wearable minicomputer or a mini smartphone in the form of a wristwatch. 
This smart watch has many capabilities like GPS navigation, monitors your heart pulse rate, body temprature adn show all the information 
on your mobile app(for now used Blynk app). 
Due to Covid-19 it is being important to track the people, so that there will be a social distancing and the spreading of the virus can be  stopped.
Our proposed system serves as a solution to this problem, it keeps tracking the health status of the person who are kept in isolation for checking wether they show symptoms of corona virus or not like high temprature and sends the health status like heart rate,  body temperature to blynk app to the higher authority in every min. 
it would be an effective solution for keeping track of person in isolation.
For detection of loaction we use gps module which provides information in the GPS standard language, NMEA. 
NMEA stands for National Marine Electronics Association, and in the world of GPS, it is a standard data format supported by GPS manufacturers.

Understanding NMEA Sentences
NMEA sentences start with the $ character, and each data field is separated by a comma.
$GPGSA – GPS DOP and active satellites
$GPGSV – Detailed GPS satellite information
$GPGLL – Geographic Latitude and Longitude
$GPRMC – Essential GPS pvt (position, velocity, time) data
$GPVTG – Velocity made good

And ESP module is used for interfacing. 

The placement of the sensors are the most important thing to get the right information or data accordingly.
Like the placement of the  heart sensor should be on the finger tip or at the earlobe.It basically detects the blood rate under the three skin layer.

The MAX30205 temperature sensor accurately measures temperature.This device converts the temperature measurements to digital form using a high-resolution, sigma-delta, analog-to-digital converter (ADC).


<---Hardware and Software Requirements--->
  
  1.ESP8266
  
  2.GPS UBlox Neo M8N
  
  3.Sparkfun Pulse Oximeter and Heart rate sensor(MAX30101)
  
  4.MAX30205 Temprature Sensor
  
  5.Blynk App


<---Process Flow--->

Firstly, the NMEA information is provided by the gps module and that information is used by the esp module to get the exact location.
Heart rate senor continuosly send the heart rate of the person to the esp and keep showing it on the mobile display. The MAX30205(Body temperature sensor) will sense the body temperature and send these information to the ESP8266 and that information is being sended to the mobile app(Blynk).On the display of the app there will be three rows showing three different data.
For the use of blynk app ESP module should be connected to it properly.

Note: Placement of the sensors should be in a proper place for the correct data.







