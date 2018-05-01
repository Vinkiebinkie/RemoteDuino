//includes
#include <SoftwareSerial.h>
#include <String.h>
#include "Adafruit_MCP9808.h"

//Pin connections
#define HC12TXPIN 10
#define HC12RCPIN 11
#define US1TRGPIN 2
#define US1ECHPIN 3
#define LIGHTPIN 4

//Communication
#define CONSOLEBAUDRATE 9600
#define HC12BAUDRATE 9600
#define DEBUGTOCONSOLE false
#define WIRELESSENABLE  true

//Settings
#define DEVICENAME "VINK"
#define EN_TEMPSENSOR true
#define EN_US1 true

//Functions
#define GETTEMP "GetTemperature"
#define GETUS1 "GetUltraSone1"
#define TOGGLELIGHT "ToggleLight"

SoftwareSerial HC12(HC12TXPIN, HC12RCPIN); // HC-12 TX Pin, HC-12 RX Pin
Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();


void SetupHC12()
{
  HC12.begin(HC12BAUDRATE);

  if (!tempsensor.begin()) 
  {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
}

void SetupUS1()
{
  pinMode(US1TRGPIN, OUTPUT);
  pinMode(US1ECHPIN, INPUT);
}

void SetupLight()
{
  pinMode(LIGHTPIN, OUTPUT);
}

void setup() {
  Serial.begin(CONSOLEBAUDRATE);             // Serial port to computer
  SetupHC12(); 
  SetupUS1();
  SetupLight();
}

void SerialWrite(String message)
{
  //Only print to console (Serial port) if enabled
  if (DEBUGTOCONSOLE)
  {
    Serial.println(message);
  }
  
  //Send wireless message if enabled
  if (WIRELESSENABLE)
  { 
    HC12.println(message);
  }
}

void ReadMessage(String message)
{
  String _command = "";
  int _index = message.indexOf(DEVICENAME);  
  
  //first filter out the device name
  if (_index >= 0)
  {
    _index += sizeof(DEVICENAME) - 1;
    _command = message.substring(_index);    
  }
  else
  {
    //If no message for this device received -> return
    return;
  }
  
  if ((_command.indexOf(GETTEMP) >= 0))
  {    
    SerialWrite(GetTemperature());
  }
  else if ((_command.indexOf(GETUS1) >= 0))
  {
    SerialWrite(GetUS1());
  }
  else if ((_command.indexOf(TOGGLELIGHT) >= 0))
  {    
    ToggleLight();
    SerialWrite("Light toggled");
  }
  
}

void ToggleLight()
{
  digitalWrite(LIGHTPIN, !digitalRead(LIGHTPIN));
}

String GetUS1()
{
  // Variabelen configureren
  long tijd, cm;
  
  // De sensor wordt getriggerd bij 10 us, geef eerst een lage puls om een schone hoge puls te krijgen
  digitalWrite(US1TRGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(US1TRGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(US1TRGPIN, LOW);
  
  // Wacht op een hoge puls en meet de tijd
  tijd = pulseIn(US1ECHPIN, HIGH);
  // De formule om tijd in afstand om te zetten
  cm = tijd / 29 / 2;

  return String(cm);
}

String GetTemperature()
{
  float _temperature;
  if (EN_TEMPSENSOR)
  {
    tempsensor.wake();
    _temperature = tempsensor.readTempC();    
    tempsensor.shutdown();
  }
  else
  {
    return "DISABLED!";
  }
  return (String(_temperature));
}

void loop() 
{
  //Create a local message string and initialize each loop
  String message = "";
  
  while (HC12.available()) // If HC-12 has data
  {        
    message += HC12.readString();    
  }

//Check if new message has been received
  if (message != "")
  {
    Serial.println("received: " + message);
    ReadMessage(message);
  }
  
}
