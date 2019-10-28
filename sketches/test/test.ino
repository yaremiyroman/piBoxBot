#include <stdio.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

struct sensor MOI_1 = { 0, "moisture_1" };
struct sensor MOI_2 = { 1, "moisture_2" };
struct sensor MOI_3 = { 2, "moisture_3" };

void setup() {
  Serial.begin(9600);
  Serial.println();
}

void printSensor(String label, float val, float val2 = NAN) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    if (isfinitef(val2)) {
      Serial.print("=");
      Serial.print(val2);
    }
    delay(PAUSE);
  }
  Serial.print("||");
}

void loop() {
  delay(PAUSE);
  Serial.print("||");

  printSensor(MOI_1.label, analogRead(MOI_1.pin));
  printSensor(MOI_2.label, analogRead(MOI_2.pin));
  printSensor(MOI_3.label, analogRead(MOI_3.pin));

  Serial.println();
  delay(REST);
}
