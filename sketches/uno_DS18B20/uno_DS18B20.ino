#include <stdio.h>
#include <DHT.h>

#define DHT_22 4
#define DHT_11_1 5
#define DHT_11_2 6
#define DHT_11_3 7

DHT dht1(DHT_22, DHT22);
DHT dht2(DHT_11_1, DHT11);
DHT dht3(DHT_11_2, DHT11);
DHT dht4(DHT_11_3, DHT11);

void setup()
{
  Serial.begin(9600);// open serial port, set the baud rate to 9600 bps

  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
}

void loop()
{
  delay(5000);
  Serial.println("=========================================");

  // DHT_22 TEMPERATURE AND HUMIDITY

  float h1 = dht1.readHumidity();
  float t1 = dht1.readTemperature();

  if (isnan(h1) || isnan(t1)) {
    Serial.print("\033[1;36mDHT_22 \033[0m >>> ");
    Serial.println("Не удается считать показания.");
  } else {
    Serial.print("\033[1;36mDHT_22 t\033[0m = ");
    Serial.print(t1);
    Serial.print("\033[1;32m deg/C\033[0m >>> \033[1;36mh\033[0m = ");
    Serial.print(h1);
    Serial.println("\033[1;32m % \033[0m");
  }

  delay(2000);


  // DHT_11 TEMPERATURE AND HUMIDITY

  float h2 = dht2.readHumidity();
  float t2 = dht2.readTemperature();

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


  // DHT_11 TEMPERATURE AND HUMIDITY

  float h3 = dht3.readHumidity();
  float t3 = dht3.readTemperature();

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



  // DHT_11 TEMPERATURE AND HUMIDITY

  float h4 = dht4.readHumidity();
  float t4 = dht4.readTemperature();

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
}
