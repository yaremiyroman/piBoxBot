#include <DHT.h>
DHT dht(4, DHT22);

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  delay(100);
  //  Serial.print("Rh > ");
  //  Serial.print(dht.readHumidity());
  //  Serial.println("%");
  //  Serial.print("T° > ");
  //  Serial.print(dht.readTemperature());
  //  Serial.println("℃ ");
  Serial.print(dht.readTemperature());
  Serial.print(",");
  Serial.print(dht.readHumidity());
  Serial.println();
  delay(1000);
}
