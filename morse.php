<!DOCTYPE html>
<html>
  <head>
    <title>Morse Translator</title>
	<style>

tr:nth-child(even) {
  background-color: #dddddd;
}
     body {
        background-color: green;
}

     h1 {
        color: white;
        text-align: center;
        font-family: arial;
        font-size: 300%;
}

     p {
        font-family: verdana;
        font-size: 20px;
        font-size: 80%;
}
	</style>

  </head>


  <body>

    <h1>C Project - Morse Translator</h1>
    <p>Type a word or a phrase into the textbox below and then press enter or go to have it translated!</p>

    <?php
       // define variables and set to empty values
       $str = $arg2 = $output = $retc = "";

       if ($_SERVER["REQUEST_METHOD"] == "POST") {
         $str = test_input($_POST["str"]);
         $arg2 = test_input($_POST["arg2"]);
         exec("/usr/lib/cgi-bin/sp1a/morsecode " . $str . " " . $arg2, $output, $retc); 
       }

       function test_input($data) {
         $data = trim($data);
         $data = stripslashes($data);
         $data = htmlspecialchars($data);
         return $data;
       }
    ?>

    <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
      Input: <input type="text" name="str"><br>
      <br>
      <input type="submit" value="Go!">
    </form>

    <?php
       // only display if return code is numeric - i.e. exec has been called
       if (is_numeric($retc)) {
         echo "<h2>Your Input:</h2>";
         echo $str;
         echo "<br>";
         echo $arg2;
         echo "<br>";
       
         echo "<h2>Program Output (an array):</h2>";
         foreach ($output as $line) {
           echo $line;
           echo "<br>";
         }
       
         echo "<h2>Program Return Code:</h2>";
         echo $retc;
       }
    ?>
    
  </body>
</html>
