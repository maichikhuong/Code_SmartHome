#include <Wire.h>
#include "UbidotsESPMQTT.h"
#define TOKEN "A1E-wLX6yElkmsNUYstFwTg8L9a1WOWYff" // Your Ubidots TOKEN
#define WIFINAME "Dell" //Your SSID
#define WIFIPASS "khuong2398" // Your Wifi Pass

Ubidots client(TOKEN);

int command[8] = {0, 1, 2, 3, 4, 5, 6, 7};
byte giatri[4] = {};
char i;
void callback(char* topic, byte* payload, unsigned int length) {
  switch (topic[20])
  {
    case '1':
      {
        if ((char)payload[0] == '0')
        {
          Serial.println(command[0]);
          giatri[0] = 0;

        }
        else
        {
          Serial.println(command[1]);
          giatri[0] = 1;

        }
        break;
      }

    case '2':
      {
        if ((char)payload[0] == '0' )
        {
          Serial.println(command[2]);
          giatri[1] = 2;

        }
        else
        {
          Serial.println(command[3]);
          giatri[1] = 3;

        }

        break;
      }

    case '3':
      {
        if ((char)payload[0] == '0' )
        {
          Serial.println(command[4]);
          giatri[2] = 4;

        }
        else
        {
          Serial.println(command[5]);
          giatri[2] = 5;

        }

        break;
      }
      case '4':
      {
        if ((char)payload[0] == '0' )
        {
          Serial.println(command[6]);
          giatri[3] = 6;

        }
        else
        {
          Serial.println(command[7]);
          giatri[3] = 7;

        }

        break;
      }
    default:
      {}
  }

}


void setup() {
  Serial.begin(9600);
  Wire.begin(D1, D2);
  client.setDebug(true);
  client.wifiConnection(WIFINAME, WIFIPASS);
  client.begin(callback);
  client.ubidotsSubscribe("input", "1");
  client.ubidotsSubscribe("input", "2");
  client.ubidotsSubscribe("input", "3");
  client.ubidotsSubscribe("input", "4");
}
void loop() {
  Wire.beginTransmission(8);
  for (i = 0; i < 3; i++)
  {
    Wire.write(giatri[i]);
  }
  Wire.endTransmission();
  delay(500);
  if (!client.connected()) {
    client.reconnect();
    client.ubidotsSubscribe("input", "1");
    client.ubidotsSubscribe("input", "2");
    client.ubidotsSubscribe("input", "3");
    client.ubidotsSubscribe("input", "4");
  }
  client.loop();
  
}
