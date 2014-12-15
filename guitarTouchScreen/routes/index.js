var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res) {
  res.render('index', { title: 'Acoustronic Guitar',
  songs: [
    {sname:"'Babe I'm Gonna Leave You'", sartist:"Led Zeppelin ", sindex: 0, img:"babe.jpg"},
  	{sname:"'Tamacun'", sartist:"Rodrigo y Gabriela", sindex:1, img:"tamacun.jpg"},
  	{sname:"Brown Eyed Girl", sartist:"Van Morrison", sindex:2, img:"brownEyedGirl.jpg"},
  	{sname:"d", sartist:"", sindex:3, img:"c"},
  	{sname:"e", sartist:"", sindex:4, img:"d"},
  	{sname:"f", sartist:"", sindex:5, img:"e"},
  	{sname:"g", sartist:"", sindex:6, img:"f"},
  	{sname:"h", sartist:"", sindex:7, img:"g"},
  	{sname:"i", sartist:"", sindex:8, img:"h"},
  	{sname:"j", sartist:"", sindex:9, img:"i"},
  ]});
});

module.exports = router;
