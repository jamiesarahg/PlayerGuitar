var express = require('express');
var router = express.Router();

/* GET home page. */
router.get('/', function(req, res) {
  res.render('index', { title: 'Express',
  songs: [
	"a",
  	"b",
  	"c",
  	"d",
  	"e",
  	"f",
  	"g",
  	"h",
  	"i",
  	"j"
  ]});
});

module.exports = router;
