#include "Adafruit_MCP9808.h"

#define I2CADDR_DEFAULT 0x18

class MCP9808: public Sensor
{
  private:
    uint8_t _I2CAddr;
    bool _fahrenheit;
    bool _powerSave = false;    
    Adafruit_MCP9808 _sensor = Adafruit_MCP9808();

  public:
    MCP9808 (String deviceName, uint8_t I2CAddr = I2CADDR_DEFAULT, bool fahrenheit = false)
    {
      SetDeviceName(deviceName);
      _I2CAddr = I2CAddr;
      _fahrenheit = fahrenheit;   

      //Check if sensor found
      if (!_sensor.begin())      
        delete this;         
    }

    String HandleCommand(String command)
    {
      Serial.println(command);
      Serial.println("WHASJOWWWEOOWEOWOE" );
      return String(GetTemperature());
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

      temperature = _sensor.readTempC();

      if (_powerSave)
        _sensor.shutdown();

      return temperature;      
    }
};
