#include <Arduino.h>
#include <WiFi.h>
#include <socket.io-client.h>

const char* ssid = "your_ssid";
const char* password = "your_password";

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.println("Connected to the WiFi network");

  // Connect to the Socket.IO server
  SocketIOClient client;
  client.begin("your_server_url");

  // Send a message to the server
  client.emit("message", "Hello from the ESP32!");

  // Listen for messages from the server
  client.on("message", [] (const String& message) {
    Serial.println("Received message: " + message);
  });
}

void loop() {
  // Handle incoming messages and events
  client.loop();
}
