var express = require('express');
var router = express.Router();

/* handle song requests */
router.post('/songs', function(req, res) {
  console.log('hi');
 // Serial.write(req.params.name);
});

module.exports = router;



