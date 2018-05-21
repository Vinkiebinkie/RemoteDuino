#include <OneWire.h> 
#include <DallasTemperature.h>

#define RW_F_GETTEMP "GETTEMP"

class RW1820 : public Sensor
{
  private:
    OneWire* _oneWire;
    DallasTemperature* _sensor;
    uint8_t _oneWirePin;

  public:
    RW1820 ( String deviceName, uint8_t oneWirePin)
    {
      SetDeviceName(deviceName);
      _oneWirePin = oneWirePin;
      _oneWire = new OneWire(_oneWirePin);
      _sensor = new DallasTemperature (&*_oneWire);

      _sensor->begin();
    }

    String HandleCommand(String command)
    {    
      if (command.indexOf(RW_F_GETTEMP)>= 0)
        return String(GetTemperature());

      return "";
    }

    float GetTemperature ()
    {
      _sensor->requestTemperatures();
      return _sensor->getTempCByIndex(0);
    }
};
