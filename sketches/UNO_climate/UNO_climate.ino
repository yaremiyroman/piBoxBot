#include <stdio.h>
#include <DHT.h>

#define DHT_22_1 2
#define DHT_11_1 3
#define DHT_11_2 4
#define DHT_11_3 5
#define DHT_11_4 6
#define DHT_11_5 7

DHT dht221(DHT_22_1, DHT22);
DHT dht111(DHT_11_1, DHT11);
DHT dht112(DHT_11_2, DHT11);
DHT dht113(DHT_11_3, DHT11);
DHT dht114(DHT_11_4, DHT11);
DHT dht115(DHT_11_5, DHT11);

void setup()
{
  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps

  dht221.begin();
  dht111.begin();
  dht112.begin();
  dht113.begin();
  dht114.begin();
  dht115.begin();
}

void loop()
{
  delay(5000);
  Serial.println("=========================================");

  // DHT_22 TEMPERATURE AND HUMIDITY

  float h0 = dht221.readHumidity();
  float t0 = dht221.readTemperature();

  if (isnan(h0) || isnan(t0)) {
    Serial.print("\033[1;36mDHT_11_1 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_1 t\033[0m = ");
    Serial.print(t0);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h0);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);

  // DHT_11 TEMPERATURE AND HUMIDITY

  float h1 = dht111.readHumidity();
  float t1 = dht111.readTemperature();

  if (isnan(h1) || isnan(t1)) {
    Serial.print("\033[1;36mDHT_11_1 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_1 t\033[0m = ");
    Serial.print(t1);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h1);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);

  float h2 = dht112.readHumidity();
  float t2 = dht112.readTemperature();

  if (isnan(h2) || isnan(t2)) {
    Serial.print("\033[1;36mDHT_11_1 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_1 t\033[0m = ");
    Serial.print(t2);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h2);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);

  float h3 = dht113.readHumidity();
  float t3 = dht113.readTemperature();

  if (isnan(h3) || isnan(t3)) {
    Serial.print("\033[1;36mDHT_11_2 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_2 t\033[0m = ");
    Serial.print(t3);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h3);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);

  float h4 = dht114.readHumidity();
  float t4 = dht114.readTemperature();

  if (isnan(h4) || isnan(t4)) {
    Serial.print("\033[1;36mDHT_11_3 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_3 t\033[0m = ");
    Serial.print(t4);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h4);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);

  float h5 = dht115.readHumidity();
  float t5 = dht115.readTemperature();

  if (isnan(h5) || isnan(t5)) {
    Serial.print("\033[1;36mDHT_11_3 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_11_3 t\033[0m = ");
    Serial.print(t5);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h5);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);


  // FIRE SENSOR

  int fireSensor = digitalRead(3);
  Serial.print("\033[1;36mFIRE SENSOR\033[0m: ");

  if (!fireSensor) {
    Serial.println("\033[1;31mON FIRE!\033[0m");
  } else {
    Serial.println("\033[1;32m CALM :)\033[0m");
  }

  delay(2000);

}
