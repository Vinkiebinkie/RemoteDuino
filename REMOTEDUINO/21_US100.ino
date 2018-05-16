#include <NewPing.h>

class UltraSone
{
  private:
    String _deviceName;
    uint8_t _triggerPin;
    uint8_t _echoPin;
    int _maxDistance;
    NewPing* _US;

  public:
    UltraSone (String deviceName, uint8_t triggerPin, uint8_t echoPin, int maxDistance = 500)
    {    
      _deviceName = deviceName;
      _triggerPin = triggerPin;
      _echoPin = echoPin;
      _maxDistance = maxDistance;

      _US = new NewPing(_triggerPin, _echoPin, _maxDistance); 
       
      pinMode(_triggerPin, OUTPUT);
      pinMode(_echoPin, INPUT);       
    }

    String GetName ()
    {
      return _deviceName;
    }

    unsigned int GetDistance ()
    {
      return _US->ping_cm();
    }
  
  
};


