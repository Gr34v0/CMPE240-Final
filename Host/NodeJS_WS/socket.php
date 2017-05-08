<?php

// Port to listen. Find out what port to use.
//~ $port = 80;

//~ $sock = socket_create_listen ($port);
//~ $client = socket_accept($sock);

//~ // read 1024 bytes from client
//~ $input = socket_read($client, 1024);

//~ echo "FROM SOCKET: " . $input . "<br>";

//~ //Will save data into DB.
//~ saveToDB($input);

//~ socket_close($client);
//~ socket_close($sock);
//~ echo $input;

function saveToDB($strText){
    //Connect to DB
    //Create sql querry
    //execute querry

    $servername = "localhost";
    $dbname = "cmpe";
    $username = "root";
    $password = "cmpe240";

    //Create connection
    $conn = mysqli_connect($servername, $username, $password, $dbname);

    //Check connection
    if(!$conn){
        die("Connection failed: " . mysqli_connect_error());
    } 
    
    echo "Connected successfully<br>";
    
    $sql = "INSERT INTO data (data) VALUES ('$input')";
    if($input != ""){
	    if(mysqli_query($conn, $sql)){
		echo "New record created successfully";
	    } 
	    else{
		echo "Error: " . $sql . "<br>" .  mysqli_error($conn);
	    }
    }

    mysqli_close($conn);
}
saveToDB("SENT FROM CLIENT");
?>
   