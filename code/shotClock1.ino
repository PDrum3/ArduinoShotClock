const int LED = 13;
const int BLINKER = 8;
const int BUTTON = 7;
int countdown = 10000;
int addedDelay = 0;

int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BLINKER, OUTPUT);
  pinMode(BUTTON, INPUT);
}

void loop() {
  val = digitalRead(BUTTON);
  countdown -= 5;
  addedDelay += 5;
  delay(5);
  if (val == HIGH) {
    countdown = 10000;
    addedDelay = 0;
    digitalWrite(LED, LOW);
    digitalWrite(BLINKER, HIGH);
  }
  if (countdown < 0) {
    digitalWrite(LED, HIGH);
  }
  if((addedDelay % 1000) == 500) {
    digitalWrite(BLINKER, LOW);
  } else if((addedDelay % 1000) == 0) {
    digitalWrite(BLINKER, HIGH);
  }

}
