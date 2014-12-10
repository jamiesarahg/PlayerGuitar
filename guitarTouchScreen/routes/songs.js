var express = require('express');
var router = express.Router();

/* handle song requests */
router.post('/songs/:name', function(req, res) {
 console.log(req.param.name);
 // Serial.write(req.params.name);
});

module.exports = router;