//Required includes
#include <SoftwareSerial.h>
#include <String.h>
#include "Adafruit_MCP9808.h"
#include <NewPing.h>


NewPing US1 (US1TRGPIN, US1ECHPIN, US1MAXDISTANCE);

SoftwareSerial HC12(HC12TXPIN, HC12RCPIN); // HC-12 TX Pin, HC-12 RX Pin

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();
