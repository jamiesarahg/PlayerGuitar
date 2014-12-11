var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res) {
  res.render('index', { title: 'Rockin Robot',
  songs: [
	  {sname:"a", sindex: 1},
  	{sname:"b", sindex:2},
  	{sname:"c", sindex:3},
  	{sname:"d", sindex:4},
  	{sname:"e", sindex:5},
  	{sname:"f", sindex:6},
  	{sname:"g", sindex:7},
  	{sname:"h", sindex:8},
  	{sname:"i", sindex:9},
  	{sname:"j", sindex:10},
  ]});
});

module.exports = router;
