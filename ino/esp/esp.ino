#include <ESP8266WiFi.h>
#include "SoftwareSerial.h"

SoftwareSerial unoSerial;

const String network = "mi";
const String pswd = "rxrxrxrx";

void setup() {
  delay(25);
  Serial.begin(115200);
  delay(25);
  Serial.println();
  delay(25);

  unoSerial.begin(9600, SWSERIAL_8N1, 12, 12, false, 256);
  unoSerial.enableIntTx(true);

  WiFi.begin(network, pswd);
  delay(25);
  Serial.print(" > Network: ");
  Serial.println(network);
  Serial.print(" Connecting.");

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
  }
  Serial.println();

  Serial.println("========== connected ==========");
  Serial.print(" > IP: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  Serial.println("\n\nUno Serial");

  Serial.print("Serial.read() >>> ");
  Serial.println(Serial.read());

  Serial.print("unoSerial->read() >>> ");
  Serial.println(unoSerial->read());

  delay(2000);
}
