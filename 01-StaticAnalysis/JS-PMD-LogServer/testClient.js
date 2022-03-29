var net = require('net');

var client = new net.Socket();
client.connect(3818, '127.0.0.1', async function() {
  console.log('Connected');

  let buf = Buffer.from('12232312321313123243434324234354354353452345235234523454352353532452345325324532')
  for (let i = 0; i < 100005; i++) {
    client.write(buf);
    await new Promise(resolve => setTimeout(resolve, 10)); // sleep for 10 ms -> cca 100 ticks per second -> 10000 in 100 secs...
  }
  console.log('finished...')
  client.destroy();
});

client.on('close', function() {
	console.log('Connection closed');
});