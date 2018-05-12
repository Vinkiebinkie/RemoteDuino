using System;
using System.Data;
using MySql.Data.MySqlClient;
using MySql.Data;

namespace RemoteDuino
{
	public class Database
	{
		private string connectionString =
			"Server=127.0.0.1;" +
			"Database=Temperatuur;" +
			"User ID=root;" +
			"Password=masterkey;" +
			"SslMode=none;" + 
			"Pooling=false";

		public MySqlConnection con;// = new MySqlConnection(connectionString);

		public Database()
		{
			con = new MySqlConnection(connectionString);
			con.Open();			
		}  
	}
}

