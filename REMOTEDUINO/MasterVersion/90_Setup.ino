#define S_SENSORCOUNT 1

Sensor* Sensors[S_SENSORCOUNT];

MCP9808* TempSensor;// = MCP9808 ("Woonkamer");
HC12* ServerComm;// = HC12 (10, 11);

void setup() {
  //Begin serial port (USB)
  Serial.begin(9600); 

  //Create needed objects
  TempSensor = new MCP9808 ("Woonkamer"); 
  ServerComm = new HC12 (10,11);  

  //Add Sensors to the Sensors array
  Sensors[0] = TempSensor;
}
