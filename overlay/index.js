const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors')

const app = express();
const port = 80;

// Configure express to user body parser
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
app.use(cors())

// For every file ending in .html in the html folder send the file to the user loading the page
app.get('/*.html?', function (req,res) {
    res.sendFile(req.url, {root: './html'});
});

var x;
var y;
var z;

app.post('/send-coords', (req, res) => {
    x = req.body.x;
    y = req.body.y;
    z = req.body.z;
    res.sendStatus(200);
});

app.post('/get-coords', (req, res) => {
    res.send({x: x, y: y, z: z});
});

app.listen(port, '0.0.0.0', () => console.log(`App listening at port ${port}`));
