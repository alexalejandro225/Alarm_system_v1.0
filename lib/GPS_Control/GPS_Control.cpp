#include "GPS_Control.h"

TinyGPSPlus tinyGPS;

void printDate()
{
  SerialMon.print(tinyGPS.date.day());
  SerialMon.print("/");
  SerialMon.print(tinyGPS.date.month());
  SerialMon.print("/");
  SerialMon.println(tinyGPS.date.year());
}

// printTime() formats the time into "hh:mm:ss", and prints leading 0's
// where they're called for.
void printTime()
{
  SerialMon.print(tinyGPS.time.hour());
  SerialMon.print(":");
  if (tinyGPS.time.minute() < 10) SerialMon.print('0');
  SerialMon.print(tinyGPS.time.minute());
  SerialMon.print(":");
  if (tinyGPS.time.second() < 10) SerialMon.print('0');
  SerialMon.println(tinyGPS.time.second());
}

void printGPSInfo()
{
  // Print latitude, longitude, altitude in feet, course, speed, date, time,
  // and the number of visible satellites.
  SerialMon.print("Lat: "); SerialMon.println(tinyGPS.location.lat(), 6);
  SerialMon.print("Long: "); SerialMon.println(tinyGPS.location.lng(), 6);
  SerialMon.print("Alt: "); SerialMon.println(tinyGPS.altitude.feet());
  SerialMon.print("Course: "); SerialMon.println(tinyGPS.course.deg());
  SerialMon.print("Speed: "); SerialMon.println(tinyGPS.speed.mph());
  SerialMon.print("Date: "); printDate();
  SerialMon.print("Time: "); printTime();
  SerialMon.print("Sats: "); SerialMon.println(tinyGPS.satellites.value());
  SerialMon.println();
}

// This custom version of delay() ensures that the tinyGPS object
// is being "fed". From the TinyGPS++ examples.
void smartDelay(unsigned long ms)
{
  unsigned long start = millis();
  do
  {
    // If data has come in from the GPS module
    while (SerialGPS.available())
      tinyGPS.encode(SerialGPS.read()); // Send it to the encode function
    // tinyGPS.encode(char) continues to "load" the tinGPS object with new
    // data coming in from the GPS module. As full NMEA strings begin to come in
    // the tinyGPS library will be able to start parsing them for pertinent info
  } while (millis() - start < ms);
}
