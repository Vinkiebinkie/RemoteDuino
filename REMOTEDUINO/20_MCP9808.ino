String GetTemperature()
{
  float _temperature;
  if (EN_TEMPSENSOR)
  {
    tempsensor.wake();
    _temperature = tempsensor.readTempC();    
    tempsensor.shutdown();
  }
  else
  {
    return "DISABLED!";
  }
  return (String(_temperature));
}
