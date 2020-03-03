const express = require('express');
const socketIo =  require('socket.io');
const http = require('http');

var path = require('path');
const app = express();
const server = http.createServer(app);
const io = socketIo.listen(server);

io.on('connection', function(socket){
    console.log('new socket connected');
});
// obtiene la ruta del directorio publico donde se encuentran los elementos estaticos (css, js).
var publicPath = path.resolve(__dirname, '/server'); //path.join(__dirname, 'public'); también puede ser una opción

// Para que los archivos estaticos queden disponibles.
app.use(express.static(publicPath));

app.get('/',(req, res, next) => {
    res.sendFile(__dirname + '/index.html');
});



const SerialPort = require('serialport');
const InterByteTimeout = require('@serialport/parser-inter-byte-timeout');
const port = new SerialPort('COM10');
const parser = port.pipe(new InterByteTimeout({interval: 30}))
var x,y,z;
parser.on('data', function(data){
    var dato = data.toString();
    console.log(dato);
    x = dato.slice(0,dato.search('/'));
    y = dato.slice(dato.search('/')+1,dato.length);
    io.emit('arduino:data',{
        x: x,
        y:y
    });

});

server.listen(3000, () =>{
    console.log('server on port 3000');
});