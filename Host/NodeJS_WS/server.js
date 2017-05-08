
var http = require('http');
var express = require('express');
var WSS = require('ws').Server;

var app = express().use(express.static('Client'));
var server = http.createServer(app);
server.listen(8080, '127.0.0.1');

var mysql = require('mysql');
var connection = mysql.createConnection({
  host     : 'localhost',
  user     : 'root',
  password : 'cmpe240',
  database : 'cmpe'
});

var wss = new WSS({ port: 8081 });
wss.on('connection', function(socket) {
  console.log('Opened Connection ');

  var json = JSON.stringify({ message: 'Gotcha' });
  socket.send(json);
  console.log('Sent: ' + json);

  socket.on('message', function(message) {
    console.log('Received: ' + message);
	writeToDB(message);

  });

  socket.on('close', function() {
    console.log('Closed Connection ');
  });

});

var broadcast = function() {
  var json = JSON.stringify({
    message: 'Hello hello!'
  });

  wss.clients.forEach(function each(client) {
    client.send(json);
    console.log('Sent: ' + json);
  });
}
setInterval(broadcast, 3000);

function writeToDB(msg){
	connection.query( "INSERT INTO data (data) VALUES ('" +msg + "')", function(err, rows, fields) {
	  if (!err)
	    console.log('The solution is: ', rows);
	  else
	    console.log('Error while performing Query.');
	});
}
