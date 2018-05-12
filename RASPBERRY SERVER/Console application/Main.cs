using System;
using System.IO.Ports;
using System.Timers;
using MySql.Data.MySqlClient;
using MySql.Data;

namespace RemoteDuino
{
	static class Program
	{
		
		private static System.Timers.Timer TempTimer;
		private static SerialComm Comm;
		private static Database Db = new Database();
		
		private static void InitPollTimer()
        {
            TempTimer = new System.Timers.Timer(10000);
            TempTimer.AutoReset = true;
            TempTimer.Elapsed += TempTimer_Elapsed;
            TempTimer.Enabled = true;            
        }
                
		private static void TempTimer_Elapsed(object sender, ElapsedEventArgs e)
        {                        
            TempTimer.Enabled = false;

            //Check if PollTimer changed            
            //TempTimer.Interval = 5000;
            Comm.mySerial.WriteLine("VINKGETTEMP");
            try
            {
				string temp = Comm.ReadData();
				decimal dec = Decimal.Parse(temp);
				InsertTESTINKS(dec);
				
			}
			catch
			{
			}
		
            TempTimer.Enabled = true;
        }
		
		public static void InsertTESTINKS (decimal Temp)
		{
			DateTime nu = DateTime.Now;
			
			string temp = $"INSERT INTO `Log`(`DateTime`, `Temperatuur`) VALUES ('{nu.ToString("yyyy-MM-dd HH:mm:ss")}', {Temp})"	;
			Console.WriteLine(temp);
			MySqlCommand cmd = new MySqlCommand (temp, Db.con);
			cmd.Prepare();
			cmd.ExecuteNonQuery();
			
			
		}
		
		
		public static void Main(string[] args)
		{
			Comm = new SerialComm();			
			//Database Db = new Database();
			//Comm.Read();
			InitPollTimer();
			while (true)
			{						
				//Comm.Read();
			}
		}
	}	

}
