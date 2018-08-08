#ifdef HC12_H
#define HC12_H

#include <SoftwareSerial.h>
#include <string>

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
    void Send (string message);
    string Receive ();    
    
};

#endif
