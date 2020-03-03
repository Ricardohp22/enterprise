const express = require('express');
const socketIo =  require('socket.io');
const http = require('http');

const app = express();
const server = http.createServer(app);
const io = socketIo.listen(server);

io.on('connection', function(socket){
    console.log('new socket connected');
});

app.get('/',(req, res, next) => {
    res.sendFile(__dirname + '/index.html');
});



const SerialPort = require('serialport');
const Readline = SerialPort.parsers.Readline;
const parser = new Readline();

const mySerial = new SerialPort('COM10',{
    baudRate: 9600
});

mySerial.on('open', function(){
    console.log('puerto abierto');
});
var datoBruto='';
var x,y,z;
mySerial.on('data',function(data){
    datoBruto += data.toString();
    /* try{
        x = datoBruto.slice(datoBruto.search('x')+1,datoBruto.search('y'));
    }catch{}
    try{
        y = datoBruto.slice(datoBruto.search('y')+1,datoBruto.search('z'));
    }catch{}
    try{
        z = datoBruto.slice(datoBruto.search('z')+1,datoBruto.search('f'));
    }catch{} */
    //datoBruto = datoBruto.split(datoBruto.search('f')+1,datoBruto.length);
    /* console.log(x +' ' + y + ' ' + z); */
    //console.log(datoBruto);
});
setInterval(function(){
    if(datoBruto.length > 0){
        if(datoBruto.search('f') >= 5){
            var paq = datoBruto.slice(0,datoBruto.search('f'));
            datoBruto = datoBruto.slice(datoBruto.search('f')+1,datoBruto.length);
            x = paq.slice(paq.search('x')+1,paq.search('y'));
            y = paq.slice(paq.search('y')+1,paq.search('z'));
            z = paq.slice(paq.search('z')+1,paq.length);
            console.log('x:' + x + ' y:' + y +' z:' + z);
            io.emit('arduino:data',{
                x: x,
                y:y,
                z:z
            });
        }
    }
},5);
server.listen(3000, () =>{
    console.log('server on port 3000');
});