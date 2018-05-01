void SetupHC12()
{
  HC12.begin(HC12BAUDRATE);

  if (!tempsensor.begin()) 
  {
    Serial.println("Couldn't find MCP9808!");
    while (1);
  }
}

void SetupUS1()
{
  pinMode(US1TRGPIN, OUTPUT);
  pinMode(US1ECHPIN, INPUT);
}

void SetupOutput1()
{
  pinMode(OUTPUT1PIN, OUTPUT);
}

void setup() {
  Serial.begin(CONSOLEBAUDRATE);             // Serial port to computer
  SetupHC12(); 
  SetupUS1();
  SetupOutput1();
}
