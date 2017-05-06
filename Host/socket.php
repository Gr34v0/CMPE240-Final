<?php

// Port to listen. Find out what port to use.
$port = 1234;

$sock = socket_create_listen ($port);
$client = socket_accept($sock);

// read 1024 bytes from client
$input = socket_read($client, 1024);

echo "FROM SOCKET: " . $input . "<br>";

//Will save data into DB.
saveToDB($input);

socket_close($client);
socket_close($sock);
echo $input;

//Will replace this with writing data into database.
function writeToFile($strFilename, $strText) { 
    if($fp = @fopen($strFilename,"w"))  { 
          $contents = fwrite($fp, $strText); 
          fclose($fp); 
          return true; 
    } 
    else { 
	return false; 
    } 
}

function saveToDB($strText){
    //Connect to DB
    //Create sql querry
    //execute querry

    $servername = "localhost";
    $username = "root";
    $password = "cmpe240";

    //Create connection
    $conn = new mysqli($servername, $username, $password);

    //Check connection
    if($conn->connect_error){
        die("Connection failed: " . $conn->connect_error);
    } 
    
    echo "Connected successfully";
    
    $sql = "INSERT INTO data (stuff) VALUES ('STUFF')";
    
    if($conn->query($sql) === TRUE){
        echo "New record created successfully";
    } 
    else{
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}
?>
   