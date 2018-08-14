#include "Sensor.h"

String Sensor::SHandleCommand(String command)
{
    return "EMPTY";
}

String Sensor::GetUnit()
{
    return Sensor::_unit;
}

String Sensor::GetSensorName()
{    
    return Sensor::_sensorName;
}

