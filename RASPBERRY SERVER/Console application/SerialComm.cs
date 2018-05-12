using System;
using System.IO.Ports;

namespace RemoteDuino
{
	public class SerialComm
	{
		public SerialPort mySerial;

		public SerialComm()
		{
			mySerial = new SerialPort("/dev/serial0", 9600);
			mySerial.Open();
			mySerial.ReadTimeout = 5000;
		}

		public void Read()
		{
			Console.WriteLine(ReadData());
		}		
		

		public string ReadData()
		{
			byte tmpByte;
			string rxString = "";

			tmpByte = (byte) mySerial.ReadByte();

			while (tmpByte != 10) 
			{
				rxString += ((char) tmpByte);
				tmpByte = (byte) mySerial.ReadByte();
			}

			return rxString;
		}
	}
}
