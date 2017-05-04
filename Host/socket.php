<?php

// Server IP address. Will need to get own IP Address.
$address = "xx.xxx.xxx.xxx";
// Port to listen. Find out what port to use.
$port = 80;

$mysock = socket_create(AF_INET, SOCK_STREAM, SOL_TCP);

socket_bind($mysock,$address, $port) or die('Could not bind to address'); 
socket_listen($mysock, 5);
$client = socket_accept($mysock);

// read 1024 bytes from client
$input = socket_read($client, 1024);

//Will save data into DB.
saveToDB($input);

socket_close($client);
socket_close($mysock);

//Will replace this with writing data into database.
function writeToFile($strFilename, $strText) { 
    if($fp = @fopen($strFilename,"w"))  { 
          $contents = fwrite($fp, $strText); 
          fclose($fp); 
          return true; 
    } else { 
      return false; 
    } 
}

function saveToDB($strText){
//Connect to DB
//Create sql querry
//execute querry
}    