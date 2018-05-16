class DigitalOutput
{
  private:
    String _deviceName;
    int _pinNumber; 

  public:
    DigitalOutput(int pinNumber, String deviceName)
    {
      pinMode(pinNumber, OUTPUT);
      _deviceName = deviceName;
      _pinNumber = pinNumber;
    }
    
    bool GetOutputState ()
    {
      return digitalRead(_pinNumber);
    }
  
    void ToggleOutput ()
    {
      digitalWrite(_pinNumber, !digitalRead(_pinNumber));  
    }
  
    void SetOutput ()
    {
      digitalWrite(_pinNumber, HIGH); 
    }

    void ResetOutput ()
    {
      digitalWrite(_pinNumber, LOW);
    }
  
};

