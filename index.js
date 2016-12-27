var express = require('express')
var config = require('./config')
var app = express()

app.listen(config.PORT, function() {
	console.log('And it began on port ' + config.PORT)
})