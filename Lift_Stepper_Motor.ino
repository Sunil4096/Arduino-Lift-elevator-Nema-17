
const int stepPin = A1;
const int dirPin = A0;
int dv = 2000;
int steps = 0;
int old_steps = 0;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
}
void loop() {
  int bt_v = map(analogRead(A5), 0, 1023, 0, 100);
  if (bt_v > 97 && bt_v < 101) {  // G
    steps = 0;
  } else if (bt_v >= 26 && bt_v <= 28) {  // 1
    steps = 500;
  } else if (bt_v >= 14 && bt_v <= 16) {  // 2
    steps = 1000;
  } else if (bt_v >= 10 && bt_v <= 12) {  // 3
    steps = 1500;
  } else if (bt_v >= 7 && bt_v <= 9) {  // 4
    steps = 2000;
  }


  if (steps >= 0 && steps <= 2000 && steps != old_steps) {
    if (steps > old_steps) {
      digitalWrite(dirPin, 0);
    } else if (steps < old_steps) {
      digitalWrite(dirPin, 1);
    }
    delay(1000);
    for (int x = 0; x < abs(old_steps - steps); x++) {
      digitalWrite(stepPin, HIGH);
      delayMicroseconds(dv);
      digitalWrite(stepPin, LOW);
      delayMicroseconds(dv);
    }
    old_steps = steps;
  }
}