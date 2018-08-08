#include "HC12.h"


HC12::HC12 (uint8_t txPin, uint8_t rxPin, uint8_t setPin = 0)
{
    HC12::_txPin = txPin;
    HC12::_rxPin = rxPin;
    HC12::_setPin = setPin;
    HC12::_port = new SoftwareSerial (HC12::_txPin, HC12::_rxPin);

    if (HC12::_setPin != 0)
    {
    pinMode(HC12::_setPin, OUTPUT);
    digitalWrite(HC12::_setPin, HIGH);
    }       
    
    HC12::_port->begin(PORTBAUDRATE);
}

void HC12::Send (string message)
{
    HC12::_port->println(message);    
}

string HC12::Receive ()
{
    string message = "";      
    while (HC12::_port->available())
    {
    message += HC12::_port->readstring();        
    }
    return message;
}