// 30+ LED Animations on Arduino Uno using 6 LEDs
// Pins: 7, 6, 5, 4, 3, 2 (LEDs 1 to 6)

const int ledPins[] = {7, 6, 5, 4, 3, 2};
const int ledCount = 6;
const int delayTime = 100;

void setup() {
  for (int i = 0; i < ledCount; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  randomSeed(analogRead(0));
}

void loop() {
  animation_forward();
  animation_reverse();
  animation_bounce();
  animation_snakeTrail();
  animation_ripple();
  animation_evenOdd();
  animation_centerOut();
  animation_outsideIn();
  animation_doubleRunner();
  animation_randomBlink();
  animation_allBlink();
  animation_pingpong();
  animation_backForthHold();
  animation_eyesBlinking();
  animation_giggling();
  animation_cartoonZap();
  animation_strobe();
  animation_shiftLeft();
  animation_shiftRight();
  animation_wave();
  animation_fireworks();
  animation_glitch();
  animation_pulse();
  animation_scanner();
  animation_sweep();
  animation_stackUp();
  animation_stackDown();
  animation_dizzyLoop();
  animation_danceFlash();
  animation_flickerChaos();
}

void clearAll() {
  for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
}

void turnOnOne(int i) {
  clearAll();
  digitalWrite(ledPins[i], HIGH);
  delay(delayTime);
  clearAll();
}

void animation_forward() { for (int i = 0; i < ledCount; i++) turnOnOne(i); }
void animation_reverse() { for (int i = ledCount - 1; i >= 0; i--) turnOnOne(i); }
void animation_bounce() { animation_forward(); animation_reverse(); }
void animation_pingpong() { animation_bounce(); }

void animation_snakeTrail() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(delayTime);
  }
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], LOW);
    delay(delayTime);
  }
}

void animation_ripple() {
  for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], HIGH);
  delay(100);
  for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
  delay(100);
}

void animation_evenOdd() {
  for (int i = 0; i < ledCount; i += 2) digitalWrite(ledPins[i], HIGH);
  delay(200); clearAll();
  for (int i = 1; i < ledCount; i += 2) digitalWrite(ledPins[i], HIGH);
  delay(200); clearAll();
}

void animation_centerOut() {
  int mid = ledCount / 2;
  for (int i = 0; i < mid; i++) {
    digitalWrite(ledPins[mid - i - 1], HIGH);
    digitalWrite(ledPins[mid + i], HIGH);
    delay(150);
    clearAll();
  }
}

void animation_outsideIn() {
  for (int i = 0; i < ledCount / 2; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[ledCount - 1 - i], HIGH);
    delay(150);
    clearAll();
  }
}

void animation_doubleRunner() {
  for (int i = 0; i < ledCount - 1; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    delay(150);
    clearAll();
  }
}

void animation_randomBlink() {
  for (int i = 0; i < 10; i++) {
    int r = random(ledCount);
    digitalWrite(ledPins[r], HIGH);
    delay(100);
    digitalWrite(ledPins[r], LOW);
  }
}

void animation_allBlink() {
  for (int j = 0; j < 3; j++) {
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], HIGH);
    delay(150);
    for (int i = 0; i < ledCount; i++) digitalWrite(ledPins[i], LOW);
    delay(150);
  }
}

void animation_backForthHold() {
  animation_forward(); delay(200);
  animation_reverse(); delay(200);
}

void animation_eyesBlinking() {
  for (int j = 0; j < 4; j++) {
    digitalWrite(ledPins[1], HIGH);
    digitalWrite(ledPins[4], HIGH);
    delay(100);
    clearAll();
    delay(100);
  }
}

void animation_giggling() {
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPins[2], HIGH);
    delay(50);
    digitalWrite(ledPins[2], LOW);
    digitalWrite(ledPins[3], HIGH);
    delay(50);
    digitalWrite(ledPins[3], LOW);
  }
}

void animation_cartoonZap() {
  for (int i = 0; i < 10; i++) {
    int r = random(ledCount);
    digitalWrite(ledPins[r], HIGH);
    delay(random(50, 150));
    digitalWrite(ledPins[r], LOW);
  }
}

void animation_strobe() {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < ledCount; j++) digitalWrite(ledPins[j], HIGH);
    delay(50);
    clearAll();
    delay(50);
  }
}

void animation_shiftLeft() {
  for (int i = 0; i < ledCount - 1; i++) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i + 1], HIGH);
    delay(100);
    clearAll();
  }
}

void animation_shiftRight() {
  for (int i = ledCount - 1; i > 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    digitalWrite(ledPins[i - 1], HIGH);
    delay(100);
    clearAll();
  }
}

void animation_wave() {
  for (int j = 0; j < 2; j++) {
    for (int i = 0; i < ledCount; i++) {
      digitalWrite(ledPins[i], HIGH);
      delay(50);
      digitalWrite(ledPins[i], LOW);
    }
  }
}

void animation_fireworks() {
  for (int i = 0; i < 10; i++) {
    int r = random(ledCount);
    digitalWrite(ledPins[r], HIGH);
    delay(75);
    digitalWrite(ledPins[r], LOW);
  }
}

void animation_glitch() {
  for (int i = 0; i < 15; i++) {
    int r = random(ledCount);
    digitalWrite(ledPins[r], random(2));
    delay(40);
  }
  clearAll();
}

void animation_pulse() {
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < ledCount; j++) digitalWrite(ledPins[j], HIGH);
    delay(200);
    clearAll();
    delay(100);
  }
}

void animation_scanner() {
  animation_forward();
  animation_reverse();
}

void animation_sweep() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    if (i > 0) digitalWrite(ledPins[i - 1], LOW);
    delay(100);
  }
  clearAll();
}

void animation_stackUp() {
  for (int i = 0; i < ledCount; i++) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  delay(200);
  clearAll();
}

void animation_stackDown() {
  for (int i = ledCount - 1; i >= 0; i--) {
    digitalWrite(ledPins[i], HIGH);
    delay(100);
  }
  delay(200);
  clearAll();
}

void animation_dizzyLoop() {
  for (int i = 0; i < 15; i++) {
    int r = i % ledCount;
    digitalWrite(ledPins[r], HIGH);
    delay(50);
    digitalWrite(ledPins[r], LOW);
  }
}

void animation_danceFlash() {
  for (int i = 0; i < 3; i++) {
    animation_evenOdd();
    animation_randomBlink();
  }
}

void animation_flickerChaos() {
  for (int i = 0; i < 20; i++) {
    for (int j = 0; j < ledCount; j++) {
      digitalWrite(ledPins[j], random(2));
    }
    delay(60);
  }
  clearAll();
}
