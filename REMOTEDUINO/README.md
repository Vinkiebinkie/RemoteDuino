
# Arduino client 

## General description



### Program layout

#### 13_HC12

HC_12 serial port module class, used for (serial) communication with the Raspberry Pi.

#### 20_Sensor

Base class used for all sensor classes, this is used to create an array of sensor to easily add sensors to the program.

#### 21_MCP9808

Adafruit I2C digital temperature sensor class.

#### 22_RW1820

Rayway International RW1820 Single-Line (onewire) Digital Temperature Sensor. 
Possibly copatible with the DS18B20.

#### 23_US100

Banana Robotics Ultrasonic Distance Sensor Module.

#### 60_DigitalOutput



#### 90_Setup

Here the objects are defined.

#### 91_MainLoop

#### 92_CommandHandler

Handles commands received from the Pi.





