#ifndef SENSOR_H
#define SENSOR_H

#include <Arduino.h>

class Sensor
{
  protected:
    String _sensorName;
    String _unit;
    
  public:
    Sensor(String sensorName) : _sensorName(sensorName){}
    virtual String SHandleCommand(String command);
    String GetUnit ();
    String GetSensorName ();
};

#endif