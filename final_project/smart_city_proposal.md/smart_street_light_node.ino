#define LDR_PIN 34
#define PIR_PIN 19
#define RELAY_PIN 23

int ambientThreshold = 500; // Darkness threshold

void setup() {
  Serial.begin(115200);
  pinMode(LDR_PIN, INPUT);
  pinMode(PIR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  int lightLevel = analogRead(LDR_PIN);
  bool motionDetected = digitalRead(PIR_PIN);
  
  // If it is dark and motion is detected, turn on the light
  if (lightLevel < ambientThreshold && motionDetected) {
    digitalWrite(RELAY_PIN, HIGH); // Light ON (Full brightness)
    Serial.println("Night + Motion: Light ON");
  } else if (lightLevel < ambientThreshold && !motionDetected) {
    // In a real scenario with PWM, we would dim the light here instead of full off
    digitalWrite(RELAY_PIN, LOW); 
    Serial.println("Night + No Motion: Light DIM/OFF");
  } else {
    digitalWrite(RELAY_PIN, LOW); // Light OFF
    Serial.println("Daytime: Light OFF");
  }
  
  delay(1000);
}
