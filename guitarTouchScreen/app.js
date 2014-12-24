var express = require('express');
var path = require('path');
var favicon = require('serve-favicon');
var logger = require('morgan');
var cookieParser = require('cookie-parser');
var bodyParser = require('body-parser');
var serialport = require('serialport')

var routes = require('./routes/index');
var users = require('./routes/users');
var songs = require('./routes/songs');


var app = express();

// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'jade');

// uncomment after placing your favicon in /public
//app.use(favicon(__dirname + '/public/favicon.ico'));
app.use(logger('dev'));
app.use(bodyParser.json());
app.use(bodyParser.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

// Serial
// var SerialPort = serialport.SerialPort;
// var serialPort = new SerialPort('/dev/ttyACM0',{//USB0", { //MUST FIND WHERE IT IS!!
// baudrate: 9600,
// parser: serialport.parsers.readline("\n")
// });
// serialData = [];
// serialPort.on('open', function () {
// serialPort.on('data', function(data) {
// console.log('data: ' + data);
// serialData.unshift(data);
// });
// });
global.songs = [
    {sname:"Brown Eyed Girl", sartist:"Van Morrison", sindex:2, img:"brownEyedGirl.jpg"},
    {sname:"Babe I'm Gonna Leave You", sartist:"Led Zeppelin ", sindex: 0, img:"babe.jpg"},
    {sname:"Tamacun", sartist:"Rodrigo y Gabriela", sindex:1, img:"tamacun.jpg"},
    
    // {sname:"d", sartist:"", sindex:3, img:"c"},
    // {sname:"e", sartist:"", sindex:4, img:"d"},
    // {sname:"f", sartist:"", sindex:5, img:"e"},
    // {sname:"g", sartist:"", sindex:6, img:"f"},
    // {sname:"h", sartist:"", sindex:7, img:"g"},
    // {sname:"i", sartist:"", sindex:8, img:"h"},
    // {sname:"j", sartist:"", sindex:9, img:"i"},
  ]

app.use('/', routes);
 app.use('/viewAll', routes)
app.use('/users', users);
app.post('/songs/:id', function(req, res) {
  //serialPort.write(req.params.id)
  console.log(req.params.id);

  res.end();
});

// catch 404 and forward to error handler
app.use(function(req, res, next) {
    var err = new Error('Not Found');
    err.status = 404;
    next(err);
});



// error handlers

// development error handler
// will print stacktrace
if (app.get('env') === 'development') {
    app.use(function(err, req, res, next) {
        res.status(err.status || 500);
        res.render('error', {
            message: err.message,
            error: err
        });
    });
}

// production error handler
// no stacktraces leaked to user
app.use(function(err, req, res, next) {
    res.status(err.status || 500);
    res.render('error', {
        message: err.message,
        error: {}
    });
});
app.get('/views/viewAll', function(req, res){
  res.send('A list of blog posts should go here');
});
app.listen(3000, function() {

    console.log("Server running on port 3000");
});
// module.exports = app;
