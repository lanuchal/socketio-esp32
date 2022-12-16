const express = require('express');
const app = express();
const http = require('http').createServer(app);
const io = require('socket.io')(http);

io.on('connection', (socket) => {
  console.log('A client connected');

  // Listen for messages from the client
  socket.on('message', (message) => {
    console.log(`Received message: ${message}`);

    // Send a message back to the client
    socket.emit('message', 'Hello from the server!');
  });
});

http.listen(3000, () => {
  console.log('Listening on port 3000');
});
