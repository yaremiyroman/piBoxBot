// #include <DHT.h>

struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;
const int REST = 1000;

// struct sensor DHT_1 = { 2, "dht1" };
// struct sensor DHT_2 = { 3, "dht2" };
// struct sensor DHT_3 = { 4, "dht3" };
// struct sensor DHT_4 = { 5, "dht4" };

// DHT dht_1(DHT_1.pin, DHT11);
// DHT dht_2(DHT_2.pin, DHT11);
// DHT dht_3(DHT_3.pin, DHT11);
// DHT dht_4(DHT_4.pin, DHT11);

void setup() {
  // pinMode(DHT_1.pin, INPUT);
  // pinMode(DHT_2.pin, INPUT);
  // pinMode(DHT_3.pin, INPUT);
  // pinMode(DHT_4.pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);

  // dht_1.begin();
  // dht_2.begin();
  // dht_3.begin();
  // dht_4.begin();

  Serial.begin(9600);
  Serial.println();
}

// void dht_out(String label, float temp, float humidity) {
//   if (isfinitef(temp) && isfinitef(humidity)) {
//     Serial.print(label);
//     Serial.print("=");
//     Serial.print(temp);
//     Serial.print("=");
//     Serial.print(humidity);
//     Serial.print("||");
//     delay(REST);
//   }
// }

void loop() {
  delay(PAUSE);
  // Serial.print("||");

  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(PAUSE);
  digitalWrite(LED_BUILTIN, LOW);
  delay(PAUSE);

  // dht_out(DHT_1.label, dht_1.readTemperature(), dht_1.readHumidity());
  // dht_out(DHT_2.label, dht_2.readTemperature(), dht_2.readHumidity());
  // dht_out(DHT_3.label, dht_3.readTemperature(), dht_3.readHumidity());
  // dht_out(DHT_4.label, dht_4.readTemperature(), dht_4.readHumidity());

  Serial.println();
  delay(REST);
}
