void SerialWrite(String message)
{
  //Only print to console (Serial port) if enabled
  if (DEBUGTOCONSOLE)
  {
    Serial.println(message);
  }
  
  //Send wireless message if enabled
  if (WIRELESSENABLE)
  { 
    HC12.println(message);
  }
}
