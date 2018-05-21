class Sensor
{
  private:
    String _deviceName;

  public:

    virtual String HandleCommand(String command){}    
  
    String GetDeviceName ()
    {
      return _deviceName;
    }

    void SetDeviceName (String deviceName)
    {
      _deviceName = deviceName;
    }
};
