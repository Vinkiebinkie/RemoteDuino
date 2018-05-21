#define S_SENSORCOUNT 1

Sensor* Sensors[S_SENSORCOUNT];

RW1820* TempSensor;
HC12* ServerComm;// = HC12 (9, 8);

void setup() {
  //Begin serial port (USB)
  Serial.begin(9600); 

  TempSensor = new RW1820("Woonkamer", 10);
  ServerComm = new HC12 (8,9);

  Sensors[0] = TempSensor;
}
