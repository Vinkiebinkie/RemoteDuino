#include <NewPing.h>

class UltraSone: public Sensor
{
  private:    
    uint8_t _triggerPin;
    uint8_t _echoPin;
    int _maxDistance;
    NewPing* _US;

  public:
    UltraSone (String deviceName, uint8_t triggerPin, uint8_t echoPin, int maxDistance = 500)
    {    
      SetDeviceName(deviceName);
      _triggerPin = triggerPin;
      _echoPin = echoPin;
      _maxDistance = maxDistance;

      _US = new NewPing(_triggerPin, _echoPin, _maxDistance); 
       
      pinMode(_triggerPin, OUTPUT);
      pinMode(_echoPin, INPUT);       
    }

    ~UltraSone ()
    {
      delete _US;
    }

    unsigned int GetDistance ()
    {
      return _US->ping_cm();
    }
  
  
};


