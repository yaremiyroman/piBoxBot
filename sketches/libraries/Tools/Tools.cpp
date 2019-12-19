// #include "Arduino.h"
#include "Tools.h"

Tools::Tools() {
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print(" >>> t = ");
    Serial.print(temp);
    Serial.print("° > h = ");
    Serial.print(humidity);
    Serial.println(" %");
  }
}

void out(String label, float val, String prefix, String postfix) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print(" >>> ");
    Serial.print(prefix);
    Serial.print(" = ");
    Serial.print(val);
    Serial.println(postfix);
  }
}
