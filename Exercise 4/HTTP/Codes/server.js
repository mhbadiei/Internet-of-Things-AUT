var express = require('express');
var app = express(); 
var bodyParser = require('body-parser') 
var fs = require('fs');


app.get('/tagdata', function (req, res) { 
  console.log("get tag data");
  const data = fs.readFileSync('tagdata.txt', 'utf8')
  console.log(data);
 
res.send(data); 
}) 

app.get('/resdata', function (req, res) { 
 console.log("get res data");
  const data = fs.readFileSync('resdata.txt', 'utf8')
  console.log(data);
 
res.send(data); 
}) 

app.use(bodyParser.urlencoded({ extended: false }));
 
app.post('/tagdata', function(req, res) {    
res.send('Got the temp data, thanks..!!');
console.log("post tag data");     
console.log(JSON.stringify(req.body));
let data = JSON.stringify(req.body);
fs.writeFile('tagdata.txt', data, function (err) {
  if (err) return console.log(err);
 //console.log('Hello World > helloworld.txt');
});
});

app.post('/resdata', function(req, res) {    
res.send('Got the temp data, thanks..!!');     
console.log("post res data");
console.log(JSON.stringify(req.body));
let data = JSON.stringify(req.body);
fs.writeFile('resdata.txt', data, function (err) {
  if (err) return console.log(err);
 //console.log('Hello World > helloworld.txt');
});
});

var server = app.listen(8081, function () {    
var host = server.address().address    
var port = server.address().port ;
console.log("Example server listening at localhost:%s", host, port) })