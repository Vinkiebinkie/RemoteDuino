#include "Sensor.h"

virtual string Sensor::HandleCommand(string command)
{

}

string Sensor::GetUnit()
{
    return Sensor::_unit;
}

string Sensor::GetSensorName()
{
    return Sensor::_sensorName;
}

