#include <stdio.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DallasTemperature.h>
#include <OneWire.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor PIRAHNIA_1 = { 2, "pirahnia_1" };
struct sensor FIRE = { 3, "fire" };
struct sensor DS18B20 = { 4, "ds18b20" };
struct sensor DHT_1 = { 5, "dht_1" };
struct sensor PIRAHNIA_2 = { 6, "pirahnia_2" };
struct sensor DHT_2 = { 7, "dht_2" };
struct sensor BUZZER = { 8, "buzzer" };
struct sensor LIGHT_1 = { 9, "light_1" };

struct sensor MOI_1 = { 0, "moi_1" };
struct sensor MOI_2 = { 1, "moi_2" };
struct sensor RAIN = { 2, "rain" };
struct sensor LIQUID = { 3, "liquid" };
struct sensor MOI_3 = { 4, "moi_3" };
struct sensor LIGHT = { 6, "light" };
struct sensor STEAM = { 7, "steam" };

DHT dht11_1(DHT_1.pin, DHT11);
DHT dht11_2(DHT_2.pin, DHT11);
OneWire oneWire(DS18B20.pin);
DallasTemperature sensors(&oneWire);

struct sensor LED = { 10, "led" };
Max72xxPanel matrix = Max72xxPanel(LED.pin, 1, 1);
const int total_pixels_in_smiley = 25;
const int total_coordinates_per_pixel = 2;
int smiley[total_pixels_in_smiley][total_coordinates_per_pixel] = {\
  {1, 0},
  {2, 0},
  {1, 1},
  {1, 2},
  {2, 1},
  {2, 2},
  {5, 0},
  {6, 0},
  {5, 1},
  {5, 2},
  {6, 1},
  {6, 2},
  {3, 1},
  {3, 2},
  {3, 3},
  {3, 4},
  {4, 4},
  {0, 5},
  {1, 6},
  {2, 7},
  {3, 7},
  {4, 7},
  {5, 7},
  {6, 6},
  {7, 5}
};

void setup() {
  Serial.begin(9600);

  dht11_1.begin();
  dht11_2.begin();
  sensors.begin();

  pinMode(PIRAHNIA_1.pin, OUTPUT);
  digitalWrite(PIRAHNIA_1.pin, LOW);

  pinMode(PIRAHNIA_2.pin, OUTPUT);
  digitalWrite(PIRAHNIA_2.pin, LOW);

  pinMode(BUZZER.pin, OUTPUT);
  digitalWrite(BUZZER.pin, HIGH);

  matrix.setIntensity(10);
  matrix.fillScreen(LOW);

  Serial.println();
}

void blink_pirahnia(int pin = 2, int count = 10, int interval = 100) {
  for (int i = 0; i <= count; i++) {
    digitalWrite(pin, HIGH);
    delay(interval);
    digitalWrite(pin, LOW);
    delay(interval);
  }
}

void buzz_buzz(int timeout = 500) {
  digitalWrite(BUZZER.pin, LOW);
  delay(timeout);
  digitalWrite(BUZZER.pin, HIGH);
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(temp);
    Serial.print("=");
    Serial.print(humidity);
    delay(PAUSE);
    Serial.print("||");
  }
}

void d_out(String label, float val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void a_out(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void animate_pixel() {
  matrix.fillScreen(LOW);

  for (int x_pixel_loc = 0; x_pixel_loc < 8; x_pixel_loc++)  {
    matrix.drawPixel(x_pixel_loc, 3, HIGH);
    matrix.write();
    delay(20);
    matrix.drawPixel(x_pixel_loc, 3, LOW);
    matrix.write();
  }

  for (int x_pixel_loc = 7; x_pixel_loc > -1; x_pixel_loc--) {
    matrix.drawPixel(x_pixel_loc, 3, HIGH);
    matrix.write();
    delay(60);
    matrix.drawPixel(x_pixel_loc, 3, LOW);
    matrix.write();
  }
}

void loop() {
  delay(PAUSE);
  sensors.requestTemperatures();
  Serial.print("||");
  animate_pixel();

  blink_pirahnia();
  d_out(FIRE.label, digitalRead(FIRE.pin));
  d_out(DS18B20.label, sensors.getTempCByIndex(0));
  dht_out(DHT_1.label, dht11_1.readTemperature(), dht11_1.readHumidity());
  buzz_buzz();
  d_out(LIGHT_1.label, digitalRead(LIGHT_1.pin));
  blink_pirahnia(PIRAHNIA_2.pin, 100, 25);
  dht_out(DHT_2.label, dht11_2.readTemperature(), dht11_2.readHumidity());

  a_out(MOI_1.label, analogRead(MOI_1.pin));
  a_out(MOI_2.label, analogRead(MOI_2.pin));
  a_out(RAIN.label, analogRead(RAIN.pin));
  a_out(LIQUID.label, analogRead(LIQUID.pin));
  a_out(MOI_3.label, analogRead(MOI_3.pin));
  a_out(LIGHT.label, analogRead(LIGHT.pin));
  a_out(STEAM.label, analogRead(STEAM.pin));

  Serial.println();
  delay(REST);
}
