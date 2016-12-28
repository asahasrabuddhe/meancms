var config = require('./config'),
	path = require('path'),
	express = require('express'),
	sass = require('node-sass'),
	sassMiddleware = require('node-sass-middleware'),
	app = express()

app.set('views', path.join(__dirname, '/resources/views'))
app.set('view engine', 'pug')

app.use(
	sassMiddleware({
		src: path.join(__dirname, '/resources/sass/'),
		dest: path.join(__dirname, '/public/assets/css'),
		includePaths: [path.join(__dirname, '/node_modules/foundation-sites/scss/')],
		prefix: '/public/assets/css/',
		debug: true,
		outputStyle: 'compressed',
	})
)

app.use('/public', express.static(__dirname + '/public'))
app.use('/public', express.static(__dirname + '/node_modules/foundation-sites/dist/js'))

app.get('/', function (req, res) {
	res.render('index',
		{ title : 'Home' }
	)
})

app.listen(config.PORT, function() {
	console.log('And it began on port ' + config.PORT)
})