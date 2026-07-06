#define TRIG_PIN 5
#define ECHO_PIN 18
#define BIN_HEIGHT_CM 100

void setup() {
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  long duration, distance_cm;
  digitalWrite(TRIG_PIN, LOW); delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH); delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);
  
  duration = pulseIn(ECHO_PIN, HIGH);
  distance_cm = (duration * 0.034) / 2;
  
  int fill_percentage = map(distance_cm, BIN_HEIGHT_CM, 10, 0, 100);
  fill_percentage = constrain(fill_percentage, 0, 100);
  
  Serial.print("Bin Fill Level: ");
  Serial.print(fill_percentage);
  Serial.println("%");
  
  // TODO: Insert LoRaWAN/MQTT payload transmission code here
  delay(60000); // Check every minute
}
