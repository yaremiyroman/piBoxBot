

#include "DHT.h"

#define DHTPIN 7 // what digital pin we're connected to

// Uncomment whatever type you're using!

#define DHTTYPE DHT11 // DHT 11


//#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

//#define DHTTYPE DHT21 // DHT 21 (AM2301)

// Initialize DHT sensor.

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(9600);

  dht.begin();

}

void loop() {

    // Wait a few seconds between measurements.

    delay(2000);

    // Reading temperature or humidity takes about 250 milliseconds!

    int h = dht.readHumidity();

    // Read temperature as Celsius (the default)

    int t = dht.readTemperature();

    Serial.print("Humidity: ");

    Serial.print(h);

    Serial.print("\t"); // for splitting

    Serial.print("Temperature: ");

    Serial.print(t);

    Serial.print("\n"); // for new line

}
