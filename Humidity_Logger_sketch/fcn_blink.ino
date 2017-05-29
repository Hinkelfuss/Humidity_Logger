void LEDblink(int LEDPin, int blinkTime) {
  for (int i = 0; i < 10; i++) {
    digitalWrite(LEDPin, HIGH);
    delay(blinkTime / 20);
    digitalWrite(LEDPin, LOW);
    delay(blinkTime / 20);
  }
}

