#include <DHT.h>
#include <DHT_U.h>


#include <Wire.h>
#include <BH1750.h>
#define DHTPIN 6
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int giatricambien[4] = {};
int giatrichuyendoi[4] = {};
byte giatritach[8] = {};
char led[4] = {3,4,2,5};
char i;
BH1750 lightMeter(0x23);
void setup() {
  Wire.begin(8);
  Wire.onReceive(receiveEvent);
  Wire.onRequest(requestEvent);
  Serial.begin(9600);
  for (i = 0; i < 4; i++)
  {
    pinMode(led[i], OUTPUT);
  }
   dht.begin();
  delay(10);
  if (lightMeter.begin(BH1750::CONTINUOUS_HIGH_RES_MODE)) {
    Serial.println(F("BH1750 Advanced begin"));
  }
  else {
    Serial.println(F("Error initialising BH1750"));
  }
}
void giatri()
{
  giatricambien[0] = dht.readHumidity();
  Serial.println(giatricambien[0]);
  delay(1000);
  giatricambien[1] = dht.readTemperature();
  Serial.println(giatricambien[1]);
  delay(1000);
  giatricambien[2] = analogRead(A0); 
  Serial.println(giatricambien[2]);
   uint16_t lux = lightMeter.readLightLevel();
   if(lux>=500){
    Serial.print("Khong co trom\n");
    giatricambien[3] = 0;
  }
  else
  {
    Serial.print("Co trom\n");
    giatricambien[3] = 1;
  }
   
}
void gtcb() {
  giatrichuyendoi[0] = map(giatricambien[0], 0, 100, 100, 200);
  giatrichuyendoi[1] = map(giatricambien[1], 0, 100, 300, 400);
  giatrichuyendoi[2] = map(giatricambien[2], 100, 200, 500, 600);
  giatrichuyendoi[3] = map(giatricambien[3], 0, 1, 700, 800);
  for (i = 0; i < 5; i++)
  {
    giatritach[2 * i] = giatrichuyendoi[i] / 255;
    giatritach[(2 * i) + 1] = giatrichuyendoi[i] % 255;
    delay(1000);

  }
}
void loop() {
  delay(100);
  giatri();
  gtcb();
}
void receiveEvent(int howMany) {
  for (i = 0; i < 4; i++)
  {
    int x = Wire.read();
    switch (x)
    {
      case 0:
        {
          
          digitalWrite(led[0], HIGH);
          break;
        }
      case 1:
        {
          
          digitalWrite(led[0], LOW);
          break;
        }
      case 2:
        {
          
          digitalWrite(led[1], 1);
          break;
        }
      case 3:
        {
         
          digitalWrite(led[1], 0);
          break;
        }
      case 4:
        {
          
          digitalWrite(led[2], 1);
          break;
        }
      case 5:
        {
          
          digitalWrite(led[2], 0);
          break;
        }
       case 6:
        {
          
          digitalWrite(led[3], 1);
          break;
        }
       case 7:
        {
          
          digitalWrite(led[3], 0);
          break;
        }
      default:
        break;
    }
  }
}
void requestEvent() {
  for (i = 0; i < 8; i++)
  {
    Wire.write(giatritach[i]);
  }
}
