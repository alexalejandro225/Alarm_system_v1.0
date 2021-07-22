#include <Arduino.h>
#include <GPS_Control.h>
#include <Sim800_Control.h>


void setup()
{
  SerialGPS.begin(9600);
}

void loop()
{
  // print position, altitude, speed, time/date, and satellites:
  printGPSInfo();

  // "Smart delay" looks for GPS data while the Arduino's not doing anything else
  smartDelay(1000); 
}




/*void updateSerial();

void setup()
{
  //Begin serial communication with Arduino and Arduino IDE (Serial Monitor)
  SerialMon.begin(115200);
  
  //Begin serial communication with Arduino and SIM800L
  pinMode(MODEM_PWKEY, OUTPUT);
  pinMode(MODEM_RST, OUTPUT);
  pinMode(MODEM_POWER_ON, OUTPUT);
  digitalWrite(MODEM_PWKEY, LOW);
  digitalWrite(MODEM_RST, HIGH);
  digitalWrite(MODEM_POWER_ON, HIGH);

  // Set GSM module baud rate and UART pins
  SerialAT.begin(115200, SERIAL_8N1, MODEM_RX, MODEM_TX);
  SerialGPS.begin(9600, SERIAL_8N1, GPS_RX, GPS_TX);
  delay(3000);
  SerialMon.println("Initializing...");
  delay(5000);

  SerialAT.println("AT"); //Once the handshake test is successful, it will back to OK
  updateSerial();
  SerialAT.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
  SerialAT.println("AT+CCID"); //Read SIM information to confirm whether the SIM is plugged
  updateSerial();
  SerialAT.println("AT+SAPBR =3,1,\"CONTYPE\",\"GPRS\"");

  SerialAT.println("AT+SAPBR=3,1,\"APN\",\"internet.itelcel.com\""); 
  updateSerial();
  SerialAT.println("AT+SAPBR=3,1,\"USER\",\"webgpr\""); 
  updateSerial();
  SerialAT.println("AT+SAPBR=3,1,\"PWD\",\"webgprs2002\""); 
  updateSerial();
  SerialAT.println("AT+SAPBR=1,1");
  updateSerial();
  SerialAT.println("AT+SAPBR=2,1");
  updateSerial();  
  SerialAT.println("AT+SAPBR =0,1");
  updateSerial(); 
}

void loop()
{
  SerialAT.println("AT+CLBS=1,1");
  updateSerial();
  SerialAT.println("AT+CSQ"); //Signal quality test, value range is 0-31 , 31 is the best
  updateSerial();
}

void updateSerial()
{
  delay(1000);
  while (SerialMon.available()) 
  {
    SerialAT.write(SerialMon.read());//Forward what Serial received to Software Serial Port
  }
  while(SerialAT.available()) 
  {
    SerialMon.write(SerialAT.read());//Forward what Software Serial received to Serial Port
  }
}
*/