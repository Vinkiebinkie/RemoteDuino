<?php
      include_once("db/db.php");
      $temperatuurobj = new Temperaturen();
      $alle_rows = $temperatuurobj->getTemperaturen();


              foreach($alle_rows as $row) {
                  echo "Datetime: " . $row["DateTime"] . "  Temperatuur: " . $row["Temperatuur"] . ",<br>";
              }
            ?>