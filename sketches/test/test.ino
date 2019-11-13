#include <stdio.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor PIRAHNIA = { 2, "led" };
struct sensor FIRE = { 3, "fire" };

struct sensor MOI = { 0, "moi" };

void setup() {
  Serial.begin(9600);

  pinMode(PIRAHNIA.pin, OUTPUT);
  digitalWrite(PIRAHNIA.pin, LOW);

  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

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

void loop() {
  delay(PAUSE);
  Serial.print("||");

  blink_pirahnia(PIRAHNIA.pin);
  d_out(FIRE.label, digitalRead(FIRE.pin));

  a_out(MOI.label, analogRead(MOI.pin));

  Serial.println();
  delay(REST);
}
