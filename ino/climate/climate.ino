#include <DHT.h>
#include <Adafruit_Sensor.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;
const int REST = 5000;

struct sensor DHT_11_1 = { 4, "dht11.a" };
struct sensor DHT_11_2 = { 5, "dht11.b" };
struct sensor DHT_11_3 = { 6, "dht11.c" };
struct sensor DHT_11_4 = { 7, "dht11.d" };
struct sensor DHT_11_5 = { 8, "dht11.e" };
struct sensor DHT_11_6 = { 9, "dht11.f" };
struct sensor DHT_11_7 = { 10, "dht11.g" };
struct sensor DHT_11_8 = { 11, "dht11.h" };

struct sensor DHT_22_1 = { 2, "dht22.a" };
struct sensor DHT_22_2 = { 3, "dht22.b" };

struct sensor DHT_2302_1 = { 12, "dht2302.a" };
struct sensor DHT_2302_2 = { 13, "dht2302.b" };

DHT dht_11_1(DHT_11_1.pin, DHT11);
DHT dht_11_2(DHT_11_2.pin, DHT11);
DHT dht_11_3(DHT_11_3.pin, DHT11);
DHT dht_11_4(DHT_11_4.pin, DHT11);
DHT dht_11_5(DHT_11_1.pin, DHT11);
DHT dht_11_6(DHT_11_2.pin, DHT11);
DHT dht_11_7(DHT_11_3.pin, DHT11);
DHT dht_11_8(DHT_11_4.pin, DHT11);

struct sensor STEAM = { 1, "steam" };

DHT dht_22_1(DHT_22_1.pin, DHT22);
DHT dht_22_2(DHT_22_2.pin, DHT22);

DHT dht_2302_1(DHT_2302_1.pin, DHT22);
DHT dht_2302_2(DHT_2302_2.pin, DHT22);

void setup() { 
  Serial.begin(9600);

  pinMode(DHT_11_1.pin, INPUT);
  pinMode(DHT_11_2.pin, INPUT);
  pinMode(DHT_11_3.pin, INPUT);
  pinMode(DHT_11_4.pin, INPUT);
  pinMode(DHT_11_5.pin, INPUT);
  pinMode(DHT_11_6.pin, INPUT);
  pinMode(DHT_11_7.pin, INPUT);
  pinMode(DHT_11_8.pin, INPUT);

  pinMode(DHT_22_1.pin, INPUT);
  pinMode(DHT_22_2.pin, INPUT);

  pinMode(DHT_2302_1.pin, INPUT);
  pinMode(DHT_2302_2.pin, INPUT);

  dht_11_1.begin();
  dht_11_2.begin();
  dht_11_3.begin();
  dht_11_4.begin();
  dht_11_5.begin();
  dht_11_6.begin();
  dht_11_7.begin();
  dht_11_8.begin();

  dht_22_2.begin();
  dht_22_1.begin();

  dht_2302_2.begin();
  dht_2302_1.begin();

  Serial.println();
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print(" >  ");
    Serial.print(temp);
    // Serial.print("℃  ");
    Serial.print("*C  ");
    Serial.print(humidity);
    Serial.print("%");
    Serial.println();
    delay(REST);
  } else {
    Serial.print(label);
    Serial.print(" >  error");
    Serial.println();
  }
}

void a_out(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    // Serial.print("||");
  }
}

void loop() {
  Serial.print("**************************************************************************");
  delay(REST);
  Serial.println();
  Serial.print("*** CLIMATE **********************************************************");
  Serial.println();
  Serial.println();
  
  dht_out(DHT_11_1.label, dht_11_1.readTemperature(), dht_11_1.readHumidity());
  dht_out(DHT_11_2.label, dht_11_2.readTemperature(), dht_11_2.readHumidity());
  dht_out(DHT_11_3.label, dht_11_3.readTemperature(), dht_11_3.readHumidity());
  dht_out(DHT_11_4.label, dht_11_4.readTemperature(), dht_11_4.readHumidity());
  dht_out(DHT_11_5.label, dht_11_5.readTemperature(), dht_11_5.readHumidity());
  dht_out(DHT_11_6.label, dht_11_6.readTemperature(), dht_11_6.readHumidity());
  dht_out(DHT_11_7.label, dht_11_7.readTemperature(), dht_11_7.readHumidity());
  dht_out(DHT_11_8.label, dht_11_8.readTemperature(), dht_11_8.readHumidity());
  Serial.println();

  dht_out(DHT_22_1.label, dht_22_1.readTemperature(), dht_22_1.readHumidity());
  dht_out(DHT_22_2.label, dht_22_2.readTemperature(), dht_22_2.readHumidity());
  Serial.println();

  dht_out(DHT_2302_1.label, dht_2302_1.readTemperature(), dht_2302_1.readHumidity());
  dht_out(DHT_2302_2.label, dht_2302_2.readTemperature(), dht_2302_2.readHumidity());
  Serial.println();

  a_out(STEAM.label, analogRead(STEAM.pin));
  Serial.println();
  Serial.println();

  delay(PAUSE);
}
