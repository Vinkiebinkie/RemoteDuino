#include "Adafruit_MCP9808.h"

#define I2CADDR_DEFAULT 0x18

class MCP9808
{
  private:
    String _deviceName;
    uint8_t _I2CAddr;
    bool _fahrenheit;
    bool _powerSave = false;
    bool _sensorFound = true;
    Adafruit_MCP9808 _sensor = Adafruit_MCP9808();

  public:
    MCP9808 (String deviceName, uint8_t I2CAddr = I2CADDR_DEFAULT, bool fahrenheit = false)
    {
      _deviceName = deviceName;
      _I2CAddr = I2CAddr;
      _fahrenheit = fahrenheit;   

      //Check if sensor found
      if (!_sensor.begin(I2CAddr))
        delete this;      
    }

    String GetName ()
    {
      return _deviceName;
    }

    bool PowerSaveEnabled ()
    {
      return _powerSave;
    }

    void EnablePowerSave()
    {
      _powerSave = true;
    }

    void DisablePowerSave()
    {
      _sensor.wake();
      _powerSave = false;
    }

    float GetTemperature()
    {
      float temperature;
      if (_powerSave)
        _sensor.wake();

      if (_fahrenheit)
        _sensor.readTempF();
      else
        _sensor.readTempC();

      if (_powerSave)
        _sensor.shutdown();

      return temperature;      
    }
};
