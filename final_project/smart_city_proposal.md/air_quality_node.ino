#define MQ135_PIN 35

void setup() {
  Serial.begin(115200);
  pinMode(MQ135_PIN, INPUT);
  // Setup code for PMS5003 UART communication goes here
}

void loop() {
  int airQualityValue = analogRead(MQ135_PIN);
  
  Serial.print("Raw Gas Sensor Value: ");
  Serial.println(airQualityValue);
  
  if(airQualityValue > 1000) {
    Serial.println("ALERT: Poor Air Quality Detected!");
  } else {
    Serial.println("Air Quality Normal.");
  }
  
  // TODO: Insert Wi-Fi/MQTT publish code here to send data to ThingSpeak
  delay(5000);
}
