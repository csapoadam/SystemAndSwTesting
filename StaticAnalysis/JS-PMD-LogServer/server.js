const path = require('path')
const fs = require('fs')
const net = require('net')
const os = require('os')
  
var SERVER;
  
const setupServer = (dataHandlerFun, closeHandler) => {
  SERVER = net.createServer();

  const handleConnection = (conn) => {
    
    var remoteAddress = conn.remoteAddress + ':' + conn.remotePort;
    console.log('new client connection from %s', remoteAddress);
    
    const onConnData = dataHandlerFun;
    
    const onConnClose = closeHandler;
    
    const onConnError = (err) => {
      console.log('Connection %s error: %s', remoteAddress, err.message);  
    }
  
    conn.on('data', onConnData);
    conn.once('close', onConnClose);
    conn.on('error', onConnError);
  }
  
  SERVER.on('connection', handleConnection);
  
  SERVER.listen(3818, function() {    
    console.log('server listening to %j', SERVER.address());  
  });
}

const args = process.argv;
const OUTPUT_FILE = args[2];

const BUF_SIZE = 3000
let DATA_BUFFER = new Array(BUF_SIZE).fill('');
let CUR_INX = 0;

const onReceiveData = (buf) => {
  let strRcvd = buf.toString('utf-8')
  let pushHandleL = parseInt(strRcvd.slice(43,48).replace(' ', ''), 16)
  let pushHandleR = parseInt(strRcvd.slice(37,42).replace(' ', ''), 16)
  let startButton = parseInt(strRcvd.slice(14,15), 16) == 4
  DATA_BUFFER[CUR_INX] = `${pushHandleL}-${pushHandleR}-${startButton}`
  CUR_INX++
  if (CUR_INX == BUF_SIZE) {
    let dte = new Date(Date.now());
    let str = DATA_BUFFER.join(os.EOL) + '-' + dte.toString() + os.EOL;
    
    fs.appendFile(OUTPUT_FILE, str, (err) => {
      if (err) console.error(err);
    })
    CUR_INX = 0;
  }
}

const onCloseHandler = () => {
  if (CUR_INX > 0) {
    let dte = new Date(Date.now()); 
    let str = DATA_BUFFER.join(os.EOL) + '-' + dte.toString() + os.EOL;
    fs.appendFile(OUTPUT_FILE, str, (err) => {
      if (err) console.error(err);
    })
  }
}

setupServer(onReceiveData, onCloseHandler);