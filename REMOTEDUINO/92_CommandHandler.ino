/*Message has following layout
 *DeviceName/Command 
 */
#define SEPERATOR_CHAR '/'

void ReadMessage (String message)
{
  if (message == "")
    return;
  
  String deviceName;
  int index;
  String tempString = message;

  if (tempString.indexOf(SEPERATOR_CHAR) > 0)
  {   
    index = tempString.indexOf(SEPERATOR_CHAR); 
    deviceName = tempString.substring(0, index);   
    tempString = tempString.substring(index+1);       
  } 

  for (int i = 0; i < 5; i++)
  {
    if (deviceName == Sensors[i]->GetDeviceName())
    {
      String response = Sensors[i]->HandleCommand(tempString);
      if (response != "");
        ServerComm->Send(response);
    }
  }
}
 
