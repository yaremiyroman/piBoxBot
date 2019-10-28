#include <stdio.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 2000;

//struct sensor MOI_1 = { 0, "moisture_1" };
//struct sensor MOI_2 = { 1, "moisture_2" };
//struct sensor MOI_3 = { 2, "moisture_3" };
struct sensor LIGHT_1 = { 3, "light_1" };
struct sensor STEAM = { 4, "steam" };

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

  printSensor(LIGHT_1.label, analogRead(LIGHT_1.pin));
  printSensor(STEAM.label, analogRead(STEAM.pin));

  Serial.println();
  delay(REST);
}
