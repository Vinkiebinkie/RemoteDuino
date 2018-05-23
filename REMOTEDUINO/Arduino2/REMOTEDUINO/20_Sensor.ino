class Sensor
{
  protected:
    String _deviceName;
    String _unit;
    
  public:

    virtual String HandleCommand(String command){} 

    String GetUnit ()
    {
      return _unit;
    }
  
    String GetDeviceName ()
    {
      return _deviceName;
    }
};
