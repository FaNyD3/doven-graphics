const express = require('express');
const app = express();
const socketIo = require('socket.io');
const http = require('http');

const server = http.createServer(app);
const io = socketIo.listen(server);

const SerialPort = require('serialport');
const Readline = SerialPort.parsers.Readline;
const parser = new Readline();

io.on('connection', function(socket) {
    console.log('new socket connected');
});

app.get('/', (req, res, next) => {
    res.sendFile(__dirname + '/index.html');
});

const mySerial = new SerialPort('COM3', { // puerto: COM3
    baudRate: 9600
});

mySerial.on('open', function() {
    console.log('Opened Serial Port');
});

mySerial.on('data', function(data) {
    console.log(data.toString());
    io.emit('arduino:data', {
        value: data.toString()
    });
});

mySerial.on('err', function() {
    console.log(err.message);
});

server.listen(4501, () => {
    console.log('server on port 4501');
});