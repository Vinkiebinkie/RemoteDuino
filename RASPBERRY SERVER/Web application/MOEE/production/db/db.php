<?php

class Temperaturen  {
        protected $db;

        public function __construct() {
           $this->db = new PDO('mysql:host=localhost;dbname=Temperatuur;charset=utf8mb4', 'root', 'masterkey');
        }

       public function getTemperaturen() {
       $stmt = $this->db->prepare("SELECT * FROM Log ORDER BY Temperatuur_datum"); /*("SELECT * FROM Log GROUP BY temperatuur ORDER BY Temperatuur_datum");*/
       $stmt->execute();
       $userRows=$stmt->fetchAll(PDO::FETCH_ASSOC);
            if($stmt->rowCount() > 0)
            {
                return $userRows;
            }
        }
}



?>