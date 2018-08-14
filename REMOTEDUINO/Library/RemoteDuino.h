#ifndef REMOTEDUINO_H
#define REMOTEDUINO_H

#define SEPERATOR '|'
#define MAX_SENSORS 10

#include <Arduino.h>
#include "Sensor.h"
#include "HC12.h"
#include "MCP9808.h"
//#include "RW1820.h"

//class HC12;

class RemoteDuino
{
    private:
        String _deviceName;
        Sensor* _sensors[MAX_SENSORS];
        HC12* _serverCommunication; 
        int _sensorCounter = 0;              
    public:
        RemoteDuino (String deviceName, uint8_t txPin, uint8_t rxPin, uint8_t setPin = 0);
        void SendToServer (String message);
        String ReceiveFromServer ();        
        void AddSensor(Sensor*& sensor);     
        String HandleCommand(String command);
};

#endif