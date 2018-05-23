/*Message has following layout
 *ArduinoName/DeviceName/Command 
 */
#define SEPERATOR_CHAR '|'
#define ARDUINONAME "VINK"

void ReadMessage (String message)
{
  //If no message received return
  if (message == "")
    return;

  Serial.println(message);
  
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

  Serial.println("Arduino name:");
  Serial.println(arduinoName);

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

  Serial.println("Device name:");
  Serial.println(deviceName);

  //Find the device with the corresponding name and handle the command
  for (int i = 0; i < S_SENSORCOUNT; i++)
  {
    Serial.println("Get device name:");
    Serial.println(Sensors[i]->GetDeviceName());
    
    if (deviceName == Sensors[i]->GetDeviceName())
    {
      String response = Sensors[i]->HandleCommand(tempString);
      if (response != "");
        ServerComm->Send(arduinoName + SEPERATOR_CHAR + deviceName + SEPERATOR_CHAR + response + SEPERATOR_CHAR + Sensors[i]->GetUnit());
    }
  }
}

 
