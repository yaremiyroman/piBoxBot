#include <DHT.h>
#include <Adafruit_Sensor.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;
const int REST = 5000;

struct sensor DHT11_1 = { 4, "dht11.a" };
struct sensor DHT11_2 = { 5, "dht11.b" };
struct sensor DHT11_3 = { 6, "dht11.c" };
struct sensor DHT11_4 = { 7, "dht11.d" };
struct sensor DHT11_7 = { 10, "dht11.g" };
struct sensor DHT11_8 = { 11, "dht11.h" };

struct sensor DHT22_1 = { 8, "dht22.a" };
struct sensor DHT22_2 = { 9, "dht22.b" };

// struct sensor DHT21_1 = { 12, "dht2302.a" };
// struct sensor DHT21_2 = { 13, "dht2302.b" };

struct sensor STEAM = { 4, "steam" };

DHT dht11_1(DHT11_1.pin, DHT11);
DHT dht11_2(DHT11_2.pin, DHT11);
DHT dht11_3(DHT11_3.pin, DHT11);
DHT dht11_4(DHT11_4.pin, DHT11);
DHT dht11_7(DHT11_3.pin, DHT11);
DHT dht11_8(DHT11_4.pin, DHT11);

DHT dht22_1(DHT22_1.pin, DHT22);
DHT dht22_2(DHT22_2.pin, DHT22);

// DHT dht21_1(DHT21_1.pin, DHT22);
// DHT dht21_2(DHT21_2.pin, DHT22);

void setup() { 
  Serial.begin(9600);

  pinMode(DHT11_1.pin, INPUT);
  pinMode(DHT11_2.pin, INPUT);
  pinMode(DHT11_3.pin, INPUT);
  pinMode(DHT11_4.pin, INPUT);
  pinMode(DHT11_7.pin, INPUT);
  pinMode(DHT11_8.pin, INPUT);

  pinMode(DHT22_1.pin, INPUT);
  pinMode(DHT22_2.pin, INPUT);

  // pinMode(DHT21_1.pin, INPUT);
  // pinMode(DHT21_2.pin, INPUT);

  dht11_1.begin();
  dht11_2.begin();
  dht11_3.begin();
  dht11_4.begin();
  dht11_7.begin();
  dht11_8.begin();

  dht22_2.begin();
  dht22_1.begin();

  // dht21_1.begin();
  // dht21_2.begin();

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
  
  dht_out(DHT11_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());
  dht_out(DHT11_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());
  dht_out(DHT11_3.label, dht11_3.readTemperature(), dht11_3.readHumidity());
  dht_out(DHT11_4.label, dht11_4.readTemperature(), dht11_4.readHumidity());
  dht_out(DHT11_7.label, dht11_7.readTemperature(), dht11_7.readHumidity());
  dht_out(DHT11_8.label, dht11_8.readTemperature(), dht11_8.readHumidity());
  Serial.println();

  dht_out(DHT22_1.label, dht22_1.readTemperature(), dht22_1.readHumidity());
  dht_out(DHT22_2.label, dht22_2.readTemperature(), dht22_2.readHumidity());
  Serial.println();

  // dht_out(DHT21_1.label, dht21_1.readTemperature(), dht21_1.readHumidity());
  // dht_out(DHT21_2.label, dht21_2.readTemperature(), dht21_2.readHumidity());
  // Serial.println();

  a_out(STEAM.label, analogRead(STEAM.pin));
  Serial.println();
  Serial.println();

  delay(PAUSE);
}
