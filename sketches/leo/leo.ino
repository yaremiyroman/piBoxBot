struct sensor {
  int pin;
  String label;
};

const int PAUSE = 750;
const int REST = 1000;
int state = 0;

struct sensor PIRAHNIA_FIRE = { 2, "piranhia_fire" };
struct sensor FIRE = { 7, "fire" };

void setup() {
  pinMode(PIRAHNIA_FIRE.pin, OUTPUT);
  pinMode(FIRE.pin, INPUT);

  Serial.println();
}

void dht_out(String label, float temp, float humidity) {
  if (isfinitef(temp) && isfinitef(humidity)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(temp);
    Serial.print("=");
    Serial.print(humidity);
    delay(PAUSE);
    Serial.print("||");
  }
}

void d_out(String label, float val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void a_out(String label, int val) {
  if (isfinitef(val)) {
    Serial.print(label);
    Serial.print("=");
    Serial.print(val);
    delay(PAUSE);
    Serial.print("||");
  }
}

void loop_start() {
  delay(PAUSE);
  Serial.print("||");
}

void loop_end() {
  Serial.println();
  delay(REST);
}

void loop() {
  // loop_start();

  state = digitalRead(FIRE.pin);

  if (state == LOW) {
    digitalWrite(PIRAHNIA_FIRE.pin, HIGH);
  }
  else {
    digitalWrite(PIRAHNIA_FIRE.pin, LOW);
  }

  // loop_end();
}
