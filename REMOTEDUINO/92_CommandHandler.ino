
void ReadMessage(String message)
{
  String _command = "";
  int _index = message.indexOf(DEVICENAME);  
  
  //first filter out the device name
  if (_index >= 0)
  {
    _index += sizeof(DEVICENAME) - 1;
    _command = message.substring(_index);    
  }
  else
  {
    //If no message for this device received -> return
    return;
  }
  
  if ((_command.indexOf(GETTEMP) >= 0))
  {    
    SerialWrite(GetTemperature());
  }
  else if ((_command.indexOf(GETUS1) >= 0))
  {
    SerialWrite(GetUS1());
  }
  else if ((_command.indexOf(OUTPUT1TOGGLE) >= 0))
  {    
    ToggleOutput1();
    SerialWrite("ToggledOK");
  }
  
}
