void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  // Blink 3 times fast
  for(int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(200);
    digitalWrite(LED_BUILTIN, LOW);
    delay(200);
  }
  
  // Pause for 2 seconds
  delay(2000);
}
