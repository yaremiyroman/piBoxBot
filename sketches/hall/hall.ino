#include <stdio.h>
#include <math.h>

struct sensor {
  int pin;
  String label;
};

struct sensor HALL = { 1,  "hall" };

const int PAUSE = 500;

void setup() { 
  Serial.begin(9600);
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
    Serial.print(">>>");
    delay(PAUSE);
  }
}

void loop() {
  delay(PAUSE);

  float hall_data = analogRead(HALL.pin);
  
  printSensor(HALL.label, hall_data);

  Serial.println();
  delay(PAUSE);
}
