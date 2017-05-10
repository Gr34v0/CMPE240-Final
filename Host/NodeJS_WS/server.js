http = require('http');
fs = require('fs');

var mysql = require('mysql');
var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'cmpe240',
    database: 'cmpe'
});


server = http.createServer( function(req, res) {

    console.dir(req.param);

	//If a POST occurs.
    if (req.method == 'POST') {
        console.log("POST");
        var body = '';
        req.on('data', function (data) {
            body += data;
            console.log("Partial body: " + body);
        });
        req.on('end', function () {
            console.log("Body: " + body);
		writeToDB(body);
        });
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.end('post received');
    }
    //If a GET occurs.
    else
    {
        console.log("GET");
        //var html = '<html><body><form method="post" action="http://localhost:3000">Name: <input type="text" name="name" /><input type="submit" value="Submit" /></form></body>';
        var html = fs.readFileSync('index.html');
	var db = getAllDB();
	    console.log(db);
        res.writeHead(200, {'Content-Type': 'text/html'});
        res.write(html + "<h1>CMPE-240 Final Project - SensorNode</h1>");
        res.write("<div id='vis'></div>");
        res.write("<script src='http://d3js.org/d3.v2.min.js'</script>");
        res.write("<script src=sine.js></script>");
        res.write("</body>");
        res.write("</html>");
        res.end();
    }

});

//The function will write the message into the database.
function writeToDB(msg) {
    connection.query("INSERT INTO data (data) VALUES ('" + msg + "')", function (err, rows, fields) {
        if (!err) {
            console.log('The solution is: ', rows);
        }
        else {
            console.log('Error while performing Query.');
        }
    });
}

function getAllDB(){
    connection.query("SELECT * FROM data", function (err, rows, fields) {
        if (!err) {
		rows = JSON.stringify(rows);
		console.log(rows);
		return rows;
        }
        else {
            console.log('Error while performing Query.');
        }
    });
}

port = 8081;
host = '127.0.0.1';
server.listen(port, host);
console.log('Listening at http://' + host + ':' + port);