#include "RemoteDuino.h"

RemoteDuino::RemoteDuino (String deviceName, uint8_t txPin, uint8_t rxPin, uint8_t setPin = 0)
{
    RemoteDuino::_deviceName=deviceName;    
    *RemoteDuino::_serverCommunication=HC12::HC12(txPin,rxPin);
    //RemoteDuino::AddSensor();
}

void RemoteDuino::SendToServer (String message)
{
    RemoteDuino::_serverCommunication->Send(message);
}

String RemoteDuino::ReceiveFromServer ()
{
    return RemoteDuino::_serverCommunication->Receive();
}

void RemoteDuino::AddSensor (Sensor*& sensor)
{    
    RemoteDuino::_sensors[RemoteDuino::_sensorCounter] = sensor;
    RemoteDuino::_sensorCounter++;
}

String RemoteDuino::HandleCommand (String command)
{
    return RemoteDuino::_sensors[0]->SHandleCommand(command);
}