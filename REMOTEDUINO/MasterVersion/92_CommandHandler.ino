/*Message has following layout
 *ArduinoName/DeviceName/Command 
 */
#define SEPERATOR_CHAR '/'
#define ARDUINONAME "VINK"

void ReadMessage (String message)
{
  //If no message received return
  if (message == "")
    return;
  
  String arduinoName;
  String deviceName;
  int index;
  String tempString = message;

  if (tempString.indexOf(SEPERATOR_CHAR) > 0)
  {   
    index = tempString.indexOf(SEPERATOR_CHAR); 
    arduinoName = tempString.substring(0, index);   
    
    //tempString will be the message minus device name
    tempString = tempString.substring(index+1);       
  } 

  //Message not for this Arduino return
  if (arduinoName != ARDUINONAME)
    return;

  //Find the (first) seperator char
  if (tempString.indexOf(SEPERATOR_CHAR) > 0)
  {       
    index = tempString.indexOf(SEPERATOR_CHAR); 
    deviceName = tempString.substring(0, index);   
    
    //tempString will be the message minus device name
    tempString = tempString.substring(index+1);       
  } 

  //Find the device with the corresponding name and handle the command
  for (int i = 0; i < S_SENSORCOUNT; i++)
  {
    if (deviceName == Sensors[i]->GetDeviceName())
    {
      String response = Sensors[i]->HandleCommand(tempString);
      if (response != "");
        ServerComm->Send(response);
    }
  }
}

 
