#include <PubSubClient.h>
#include "UbidotsESPMQTT.h"
#include <Wire.h>
#define TOKEN "A1E-wLX6yElkmsNUYstFwTg8L9a1WOWYff"
#define WIFISSID "Dell"
#define PASSWORD "khuong2398"
Ubidots client(TOKEN);
byte giatrinhanve[8] = {};
int giatrighep[4] = {};
int giatricuoicung[4] = {};
int i;
void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i=0;i<length;i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}
void nhangiatri() {
  Wire.requestFrom(8, 13);
  for (i = 0; i < 8; i++)
  {
    giatrinhanve[i] = Wire.read();
  }
  for (i = 0; i < 4; i++)
  {

    giatrighep[i] = giatrinhanve[(2 * i) ] * 255 + giatrinhanve[(2 * i) + 1];
    delay(1000);

  }
  giatricuoicung[0] = map(giatrighep[0], 100, 200, 0, 100);
  giatricuoicung[1] = map(giatrighep[1], 300, 400, 0, 100);
  giatricuoicung[2] = map(giatrighep[2], 500, 600, 100, 200);
  giatricuoicung[3] = map(giatrighep[3], 700, 800, 0, 1);
  

}
void setup() {
  Serial.begin(9600);
  Wire.begin(D1, D2);
  client.wifiConnection(WIFISSID, PASSWORD);
  client.setDebug(true);
  client.begin(callback);
}
void loop() {
  nhangiatri();
  if(!client.connected()){
      client.reconnect();
  }
  client.add("temp", giatricuoicung[1]);
  client.add("Humi", giatricuoicung[0]);
  client.add("gas", giatricuoicung[2]);
  client.ubidotsPublish("HomeData");
  client.add("window", giatricuoicung[3]);
  client.ubidotsPublish("SecureData");
  client.loop();
  delay(5000);
}
