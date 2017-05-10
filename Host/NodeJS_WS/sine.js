var samples, data, width, height, margin, w, h, xScale, yScale, svg, xAxis, yAxis, line, g, path;
var mysql = require('mysql');
var connection = mysql.createConnection({
    host: 'localhost',
    user: 'root',
    password: 'cmpe240',
    database: 'cmpe'
});

samples = Math.PI * 3;
//data = generateSineData(samples);
data = JSON.parse(getAllDB());
width = 800;
height = 500;
margin = {
  top: 10,
  right: 10,
  bottom: 40,
  left: 40
};
w = width - margin.right;
h = height - margin.top - margin.bottom;
xScale = d3.scale.linear().domain([0, samples - 1]).range([0, w]);
yScale = d3.scale.linear().domain([-1, 1]).range([h, 0]);
svg = d3.select('#vis').append('svg').attr('width', w + margin.left + margin.right).attr('height', h + margin.top + margin.bottom).append('g').attr('transform', "translate(" + margin.left + ", " + margin.top + ")");
svg.append("defs").append("clipPath").attr("id", "clip").append("rect").attr("width", w).attr("height", h);
xAxis = d3.svg.axis().scale(xScale).ticks(10).orient('bottom');
svg.append('g').attr('class', 'x axis').attr("transform", "translate(0," + h + ")").call(xAxis);
yAxis = d3.svg.axis().scale(yScale).ticks(5).orient('left');
svg.append('g').attr('class', 'y axis').call(yAxis);

line = d3.svg.line().x(function(d, i){
  return xScale(i);
}).y(function(d, i){
  return yScale(d);
}).interpolate('basis');

g = svg.append('g').attr('clip-path', 'url(#clip)');

path = g.append('path').attr('class', 'line').data([data]).attr('d', line).style('fill', 'none').style('stroke', 'black').style('stroke-width', '1px');

function generateSineData(samples){
  return d3.range(0, 100).map(function(i){
    return Math.sin(i);
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