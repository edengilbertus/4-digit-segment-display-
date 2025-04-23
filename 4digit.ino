const int numLEDs = 5;
const int ledPins[] = {9, 10, 11, 12, 13};
int currentPattern = 0;
int repeatCount = 0;

void setup() {
  for (int i = 0; i < numLEDs; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
}

void loop() {
  allLEDsOff();

  switch (currentPattern) {
    case 0:
      fillRightToLeft();
      break;
    case 1:
      clearLeftToRight();
      break;
    case 2:
      twoLEDsMovingRight();
      break;
    case 3:
      twoLEDsMovingLeft();
      break;
    case 5:
      meetingLEDs();
      break;
    case 6:
      oppositePhase2();
      break;
  }

  if (currentPattern == 4) {
    repeatCount++;
    if (repeatCount >= 3) {
      repeatCount = 0;
      currentPattern++;
    } else {
      currentPattern = 2;
    }
  } else {
    currentPattern++;
  }

  if (currentPattern > 6) {
    currentPattern = 0;
  }

  delay(800);
}

void allLEDsOff() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
  }
}

void fillRightToLeft() {
  for (int i = numLEDs - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
  }
}

void clearLeftToRight() {
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(200);
  }
}

void twoLEDsMovingRight() {
  for (int i = 0; i < numLEDs - 1; i++) {
    allLEDsOff();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    delay(200);
  }
}

void twoLEDsMovingLeft() {
  for (int i = numLEDs - 1; i > 0; i--) {
    allLEDsOff();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i - 1], HIGH);
    delay(200);
  }
}

void meetingLEDs() {
  for (int i = 0; i < numLEDs / 2 + 1; i++) {
    allLEDsOff();
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[numLEDs - 1 - i], HIGH);
    delay(200);
  }
}

void oppositePhase2() {
  allLEDsOff();
  for (int i = 0; i < numLEDs; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(200);
  }
}
