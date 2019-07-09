#include <stdio.h>
#include <DHT.h>

#define DHT11_1 4
#define DHT11_2 5
#define DHT11_3 6
#define DHT11_4 7

#define DHT22_1 8
//#define DHT22_1 9
//#define DHT22_1 10
//#define DHT22_1 11

DHT dht111(DHT11_1, DHT11);
DHT dht112(DHT11_2, DHT11);
DHT dht113(DHT11_3, DHT11);
DHT dht114(DHT11_4, DHT11);

DHT dht221(DHT22_1, DHT22);

int pause = 2500;
int interval = 5000;
int rest = 15000;

void setup() {
  pinMode(DHT11_1, OUTPUT);
  pinMode(DHT11_2, OUTPUT);
  pinMode(DHT11_3, OUTPUT);
  pinMode(DHT11_4, OUTPUT);

  pinMode(DHT22_1, OUTPUT);

  dht111.begin();
  dht112.begin();
  dht113.begin();
  dht114.begin();

  dht221.begin();

  Serial.begin(9600);
}

void loop() {
  delay(interval);

  // DHT11
  float h1 = dht111.readHumidity();
  delay(pause);
  float t1 = dht111.readTemperature();
  delay(pause);
  float h2 = dht112.readHumidity();
  delay(pause);
  float t2 = dht112.readTemperature();
  delay(pause);
  float h3 = dht113.readHumidity();
  delay(pause);
  float t3 = dht113.readTemperature();
  delay(pause);
  float h4 = dht114.readHumidity();
  delay(pause);
  float t4 = dht114.readTemperature();
  delay(pause);
  // DHT22
  float h5 = dht221.readHumidity();
  delay(pause);
  float t5 = dht221.readTemperature();
  delay(pause);

  if (!isnan(h1) && !isnan(t1)) {
    Serial.print(">>>t4=");
    Serial.print(t1);
    Serial.print("<<<");
    Serial.print(">>>h4=");
    Serial.print(h1);
    Serial.print("<<<");
  }

  if (!isnan(h2) && !isnan(t2)) {
    Serial.print(">>>t5=");
    Serial.print(t2);
    Serial.print("<<<");
    Serial.print(">>>h5=");
    Serial.print(h2);
    Serial.print("<<<");
  }

  if (!isnan(h3) && !isnan(t3)) {
    Serial.print(">>>t6=");
    Serial.print(t3);
    Serial.print("<<<");
    Serial.print(">>>h6=");
    Serial.print(h3);
    Serial.print("<<<");
  }

  if (!isnan(h4) && !isnan(t4)) {
    Serial.print(">>>t7=");
    Serial.print(t4);
    Serial.print("<<<");
    Serial.print(">>>h7=");
    Serial.print(h4);
    Serial.print("<<<");
  }

  if (!isnan(h5) && !isnan(t5)) {
    Serial.print(">>>t8=");
    Serial.print(t5);
    Serial.print("<<<");
    Serial.print(">>>h8=");
    Serial.print(h5);
    Serial.print("<<<");
  }

  Serial.println();
  delay(rest);
}
