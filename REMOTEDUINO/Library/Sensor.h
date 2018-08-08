#ifndef SENSOR_H
#define SENSOR_H

#include <string>

class Sensor
{
  protected:
    string _sensorName;
    string _unit;
    
  public:

    virtual string HandleCommand(string command);
    string GetUnit ();
    string GetSensorName ();
};

#endif