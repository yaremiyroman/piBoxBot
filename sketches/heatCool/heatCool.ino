#include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 1000;

struct sensor DHT_11 = { 2, "DHT" };
struct sensor btn_blue = { 3, "blue button" };
struct sensor led_red = { 5, "led_red" };
struct sensor led_green = { 6, "led_green" };
struct sensor led_white = { 7, "led_white" };
struct sensor fan = { 13, "fan" };

struct sensor moi = { 0, "moi" };

DHT dht(DHT_11.pin, DHT11);

void setup() {
  dht.begin();
  pinMode(btn_blue.pin, INPUT);

  pinMode(led_red.pin, OUTPUT);
  pinMode(led_green.pin, OUTPUT);
  pinMode(led_white.pin, OUTPUT);

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

void loop() {
  digitalWrite(led_white.pin, LOW);
  analogWrite(led_green.pin, 1);
  analogWrite(fan.pin, 1023);

  if (dht.readTemperature() < 24) {
    digitalWrite(led_red.pin, HIGH);
  } else {
    digitalWrite(led_red.pin, LOW);
  }

  delay(PAUSE);
  Serial.print("||");

  if (digitalRead(btn_blue.pin) == HIGH) {
    digitalWrite(led_white.pin, HIGH);
  } else {
    digitalWrite(led_white.pin, LOW);
  }

  dht_out(DHT_11.label, dht.readTemperature(), dht.readHumidity());

  a_out(moi.label, analogRead(moi.pin));

  Serial.println();
  delay(PAUSE);
}
