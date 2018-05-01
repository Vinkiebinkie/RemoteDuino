# RemoteDuino

##Idea

RemoteDuino exists of a Arduino (Uno) and a Raspberry Pi 3 (model B+). The Arduino functions as a client with a serial connection to the Raspberry Pi, which functions as a server.
Commands can be send from the server to the client to retrieve sensor data, switch outputs etc. etc. anything that can be connected to the Arduino really. 

The communication between server and client is wireless, in my case with HC-12 transceivers, these are easy to use wireless serial port modules.

#Arduino client 

##General description

The idea is to create one program where sensors can be "configured" by changing the main program file.

###Program layout

####REMOTEDUINO

Configuration is done on the basis of defines. The configuration is split in different sections:

- Pin connections; these are the electrical connections to the Arduino (Digital pins)
- Communication settings; baudrates of the serial communication
- Settings; the device name and enabling of certain functions
- Functions; naming of the functions, this is used in the communication as commands from the slave

####10_Functions

The different functions used in the program are declared here, this is used for a overview of the functions per program file.

####11_Global

Includes and global variables.

####12_Setup

Setup of  functions required to make stuff work.

####13_SerialWrite

Writing to the serial interface.

####14_SerialRead

Reading from the serial interface.

####20_MCP9808

MCP9808 temperature sensor.

####21_US100

Ultra sone sensor for measuring distance.

####30_DigitalOutput

Digital output control

####99_MainLoop

The main loop





