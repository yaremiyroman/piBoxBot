#include <stdio.h>
//#include <DHT.h>
//#include <OneWire.h>
//#include <Adafruit_Sensor.h>
//#include <DallasTemperature.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;

//struct sensor DS18B20 = { 2, "ds18b20" };
//struct sensor DHT_1 = { 4, "dht11_1" };
//struct sensor DHT_2 = { 5, "dht11_2" };
//struct sensor DHT_3 = { 6, "dht11_3" };
//struct sensor DHT_4 = { 7, "dht11_4" };

struct sensor STEAM = { 0, "steam" };
struct sensor LIGHT = { 1, "light" };
//struct sensor MOI_1 = { 4, "moi_1" };
//struct sensor MOI_2 = { 5, "moi_2" };

//DHT dht11_1(DHT_1.pin, DHT11);
//DHT dht11_2(DHT_2.pin, DHT11);
//DHT dht11_3(DHT_3.pin, DHT11);
//DHT dht11_4(DHT_4.pin, DHT11);
//OneWire oneWire(DS18B20.pin);
//DallasTemperature sensors(&oneWire);

void setup() {
  //  dht11_1.begin();
  //  dht11_2.begin();
  //  dht11_3.begin();
  //  dht11_4.begin();
  //  sensors.begin();

  Serial.begin(9600);

  Serial.println();
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(temp);
    Serial.print("=");
    Serial.print(humidity);
    Serial.print("||");
    delay(PAUSE);
  }
}

void d_out(String label, float val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    Serial.print("||");
    delay(PAUSE);
  }
}

void a_out(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    Serial.print("||");
    delay(PAUSE);
  }
}

void loop_start() {
  delay(PAUSE);
  //  sensors.requestTemperatures();
  Serial.print("||");
}

void loop_end() {
  Serial.println();
  delay(PAUSE);
}

void loop() {
  loop_start();

  //  d_out(DS18B20.label, sensors.getTempCByIndex(0));
  //  dht_out(DHT_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());
  //  dht_out(DHT_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());
  //  dht_out(DHT_3.label, dht11_3.readTemperature(), dht11_3.readHumidity());
  //  dht_out(DHT_4.label, dht11_4.readTemperature(), dht11_4.readHumidity());

  a_out(STEAM.label, analogRead(STEAM.pin));
  a_out(LIGHT.label, analogRead(LIGHT.pin));
  //  a_out(MOI_1.label, analogRead(MOI_1.pin));
  //  a_out(MOI_2.label, analogRead(MOI_2.pin));

  loop_end();
}
