Sensor* Sensors[5];

MCP9808* TempSensor;// = MCP9808 ("Woonkamer");
HC12* ServerComm;// = HC12 (10, 11);

void setup() {
  Serial.begin(9600); 
  TempSensor = new MCP9808 ("Woonkamer"); 
  ServerComm = new HC12 (10,11);  

  Sensors[0] = TempSensor;
}
