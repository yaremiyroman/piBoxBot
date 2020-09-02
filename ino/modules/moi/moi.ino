struct sensor {
  int pin;
  String label;
};

const int PAUSE = 250;
const int REST = 500;

struct sensor moi = { 5, "moi" };

void setup() {
  Serial.begin(9600);
  Serial.println();
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

void loop() {
  Serial.print("*******************************************");
  delay(REST);
  Serial.println();
  Serial.println();
  Serial.println();

  a_out(moi.label, analogRead(moi.pin));

  Serial.println();
  Serial.println();
  delay(PAUSE);
}
