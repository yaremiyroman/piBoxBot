#include <stdio.h>
#include <DHT.h>

#define DHT11_1 4
#define DHT11_2 5
#define DHT11_3 6
#define DHT11_4 7

//#define DHT22_1 4
//#define DHT22_1 5
//#define DHT22_1 6
//#define DHT22_1 7

DHT dht111(DHT11_1, DHT11);
DHT dht112(DHT11_2, DHT11);
DHT dht113(DHT11_3, DHT11);
DHT dht114(DHT11_4, DHT11);

//DHT dht221(DHT22_1, DHT22);

int pause = 500;
int interval = 2000;
int rest = 5000;

void setup() {
  //  pinMode(DHT11_1, OUTPUT);
  //  pinMode(DHT11_2, OUTPUT);

  dht111.begin();
  dht112.begin();
  dht113.begin();
  dht114.begin();

  //  dht221.begin();

  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps
}

void loop() {
  delay(interval);
  Serial.println("========================================================");
  delay(interval);

  // DHT11
  float h1 = dht111.readHumidity();
  delay(pause);
  float t1 = dht111.readTemperature();
  delay(pause);
  float h2 = dht112.readHumidity();
  delay(pause);
  float t2 = dht112.readTemperature();
  delay(pause);
  float h3 = dht113.readHumidity();
  delay(pause);
  float t3 = dht113.readTemperature();
  delay(pause);
  float h4 = dht114.readHumidity();
  delay(pause);
  float t4 = dht114.readTemperature();
  delay(pause);

  if (isnan(h1) || isnan(t1)) {
    Serial.print("\033[1;36mDHT11_1 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT11_1 t\033[0m = ");
    Serial.print(t1);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h1);
    Serial.println("\033[1;32m % \033[0m");
  }

  if (isnan(h2) || isnan(t2)) {
    Serial.print("\033[1;36mDHT11_2 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT11_2 t\033[0m = ");
    Serial.print(t2);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h2);
    Serial.println("\033[1;32m % \033[0m");
  }

  if (isnan(h3) || isnan(t3)) {
    Serial.print("\033[1;36mDHT11_3 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT11_3 t\033[0m = ");
    Serial.print(t3);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h3);
    Serial.println("\033[1;32m % \033[0m");
  }

  if (isnan(h4) || isnan(t4)) {
    Serial.print("\033[1;36mDHT11_4 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT11_4 t\033[0m = ");
    Serial.print(t4);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h4);
    Serial.println("\033[1;32m % \033[0m");
  }

  //  delay(interval);

  // DHT22
  //  float h5 = dht221.readHumidity();
  //  delay(pause);
  //  float t5 = dht221.readTemperature();
  //  delay(pause);
  //
  //  if (isnan(h5) || isnan(t5)) {
  //    Serial.print("\033[1;36mDHT22_1 \033[0m >>> ");
  //    Serial.println("Не удается считать показания.");
  //  } else {
  //    Serial.print("\033[1;36mDHT22_1 t\033[0m = ");
  //    Serial.print(t5);
  //    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
  //    Serial.print(h5);
  //    Serial.println("\033[1;32m % \033[0m");
  //  }
}
