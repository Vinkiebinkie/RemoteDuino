#ifndef MCP9808_H
#define MCP9808_H

#include <Arduino.h>
#include "Adafruit_MCP9808.h"
#include "Sensor.h"
#include <Wire.h>

#define I2CADDR_DEFAULT 0x18
#define MCP_F_GETTEMP "GETTEMP"


class MCP9808: public Sensor
{
  private:
    uint8_t _I2CAddr;
    bool _fahrenheit;
    bool _powerSave = true;    
    Adafruit_MCP9808 _sensor = Adafruit_MCP9808();

  public:
    MCP9808 (String sensorName, uint8_t I2CAddr = I2CADDR_DEFAULT, bool fahrenheit = false);
    virtual String SHandleCommand(String command);
    float GetTemperature();
    bool PowerSaveEnabled ();
    void EnablePowerSave();
    void DisablePowerSave();
};

#endif