//setup
void SerialWrite(String message);
void SetupHC12();
void SetupUS1();
void SetupOutput1();


//SerialWrite
void SerialWrite(String message);

//SerialRead
void SerialRead();
void ReadMessage(String message);

//MCP9808
String GetTemperature();


//US-100
String GetUS1();

//DigitalOutput
void ToggleOutput1();
