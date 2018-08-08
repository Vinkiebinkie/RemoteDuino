#ifndef REMOTEDUINO_H
#define REMOTEDUINO_H

#define SEPERATOR '|'
#define MAX_SENSORS 10

#include <string>
#include "Sensor.h"
#include "HC12.h"

class REMOTEDUINO
{
    private:
        string _deviceName;
        Sensor* _sensors[MAX_SENSORS];
        HC12* _serverCommunication;
    public:
        

};

#endif