#include <SoftwareSerial.h>

#define PORTBAUDRATE 9600

class HC12
{
  private:
    uint8_t _txPin;
    uint8_t _rxPin;
    uint8_t _setPin;
    SoftwareSerial* _port;
    
  public:
    HC12 (uint8_t txPin, uint8_t rxPin, uint8_t setPin = 0)
    {
      _txPin = txPin;
      _rxPin = rxPin;
      _setPin = setPin;
      _port = new SoftwareSerial (_txPin, _rxPin);

      if (_setPin != 0)
      {
        pinMode(_setPin, OUTPUT);
        digitalWrite(_setPin, HIGH);
      }       
      
      _port->begin(PORTBAUDRATE);
    }

    void Send (String message)
    {
      _port->println(message);    
    }

    String Receive ()
    {
      String message = "";      
      while (_port->available())
      {
        message += _port->readString();
      }
      return message;
    }
    
};

