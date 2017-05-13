http = require('http');
fs = require('fs');

//Creates the connection to the db.
var mysql = require('mysql');
var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'cmpe240',
    database: 'cmpe'
});

//Creates the actual webserver.
server = http.createServer(function(req, res){

    console.dir(req.param);

	//If a POST occurs.
    if (req.method == 'POST'){
        console.log("POST");
        var body = '';
        req.on('data', function(data){
            body += data;
            console.log("Partial body: " + body);
        });
        req.on('end', function(){
            console.log("Body: " + body);
			writeToDB(body);
        });
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.end('post received');
    }
	
    //If a GET occurs.
    else{
		console.log("GET");
		var html = fs.readFileSync('index.html');
		var db = getAllDB();
		res.writeHead(200, {'Content-Type': 'text/html'});
		res.write(html);
		connection.query("SELECT * FROM data", function (err, rows, fields){
			if(!err){
				//rows = JSON.stringify(rows);
				console.log(rows);
				for (x in rows){
					res.write(""+rows[x]["data"]);
					res.write("<br>");
				}
			}
			else {
				console.log('Error while performing Query.');
			}
		});

       //res.end();
	}
});

//The function will write the message into the database.
function writeToDB(msg){
    connection.query("INSERT INTO data (data) VALUES ('" + msg + "')", function (err, rows, fields) {
        if (!err){
            console.log('The solution is: ', rows);
        }
        else{
            console.log('Error while performing Query.');
        }
    });
}

//Just queries the db and returns all of the data.
function getAllDB(){
    connection.query("SELECT * FROM data", function (err, rows, fields) {
        if (!err){
			//rows = JSON.stringify(rows);
			console.log(rows);
			return rows;
        }
        else{
            console.log('Error while performing Query.');
        }
    });
}

//Determines what port to use and what address to use.
port = 8081;
host = '192.168.43.250';
server.listen(port, host);
console.log('Listening at http://' + host + ':' + port);