#ifndef HC12_H
#define HC12_H

#include <SoftwareSerial.h>
#include <Arduino.h>

#define PORTBAUDRATE 9600

class HC12
{
  private:
    uint8_t _txPin;
    uint8_t _rxPin;
    uint8_t _setPin;
    SoftwareSerial* _port;
    
  public:
    HC12 (uint8_t txPin, uint8_t rxPin, uint8_t setPin = 0);    
    void Send (String message);
    String Receive ();    
    
};

#endif
