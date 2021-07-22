#ifndef HEADER_FILE
#define HEADER_FILE

#include <TinyGPS++.h>
#include <Arduino.h>

#define GPS_TX               34
#define GPS_RX               35

//Set serial for debug console (to Serial Monitor, default speed 115200)
#define SerialMon Serial

//Set  serial for GPS module
#define SerialGPS Serial2

//GPS functions for data acquisition 
void printDate();
void printTime();
void printGPSInfo();
void smartDelay(unsigned long ms);

#endif
