#include "MCP9808.h"

    MCP9808::MCP9808 (String sensorName, uint8_t I2CAddr = I2CADDR_DEFAULT, bool fahrenheit = false)
      :Sensor(sensorName)
    {    
      
      MCP9808::_unit = "C";
      //MCP9808::_sensorName = sensorName;     
      MCP9808::_I2CAddr = I2CAddr;
      MCP9808::_fahrenheit = fahrenheit;  

      //Check if sensor found
      if (!MCP9808::_sensor.begin())      
          delete this;         
    }

    String MCP9808::SHandleCommand(String command)
    {
      //Serial.println(command);
      if (command.indexOf(MCP_F_GETTEMP)>= 0)
        return String(MCP9808::GetTemperature());

      return "FAILED";
    }

    bool MCP9808::PowerSaveEnabled ()
    {
      return MCP9808::_powerSave;
    }

    void MCP9808::EnablePowerSave()
    {
      MCP9808::_powerSave = true;
    }

    void MCP9808::DisablePowerSave()
    {
      MCP9808::_sensor.wake();
      MCP9808::_powerSave = false;
    }

    float MCP9808::GetTemperature()
    {
        //return 69.69;

        float temperature;
        if (MCP9808::_powerSave)
            MCP9808::_sensor.wake();

    
        temperature = MCP9808::_sensor.readTempC();

        if (MCP9808::_powerSave)
            MCP9808::_sensor.shutdown();

        return temperature;      
    }