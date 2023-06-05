#include <DHT.h>
#include <DHT_U.h>

DHT dht(4, DHT22);

int chk;
float hum;
float temp;

void setup()
{
  Serial.begin(9600);
  dht.begin();
}

void loop()
{
  hum = dht.readHumidity();
  temp = dht.readTemperature();
  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.print(" %, Temp: ");
  Serial.print(temp);
  Serial.println(" Celsius");
  delay(2000);
}
