struct sensor {
  int pin;
  String label;
};

const int PAUSE = 500;

struct sensor BTN_BLUE = { 4, "blue button" };
struct sensor TEPLIK = { 7, "teplik" };

void setup() {
  pinMode(TEPLIK.pin, OUTPUT);
  pinMode(BTN_BLUE.pin, INPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(PAUSE);

  if (digitalRead(BTN_BLUE.pin) == HIGH) {
    digitalWrite(TEPLIK.pin, HIGH);
    digitalWrite(LED_BUILTIN, HIGH);
  } else {
    digitalWrite(TEPLIK.pin, LOW);
    digitalWrite(LED_BUILTIN, LOW);
  }

  delay(PAUSE);
}
