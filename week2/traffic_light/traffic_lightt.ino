int redPin = 3;
int yellowPin = 4;
int greenPin = 5;
int buttonPin = 7;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  Serial.print("Time: ");
  Serial.print(millis()); 
  Serial.println(" ms | State: RED");
  for (int i = 0; i < 50; i++) {
    if (digitalRead(buttonPin) == LOW) { pedestrianMode(); return; }
    delay(100); 
  }
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);  
  Serial.print("Time: "); 
  Serial.print(millis());
  Serial.println(" ms | State: YELLOW");
  for (int i = 0; i < 20; i++) {
    if (digitalRead(buttonPin) == LOW) { pedestrianMode(); return; }
    delay(100);
  }
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  Serial.print("Time: "); 
  Serial.print(millis()); 
  Serial.println(" ms | State: GREEN");
  for (int i = 0; i < 40; i++) {
    if (digitalRead(buttonPin) == LOW) { pedestrianMode(); return; }
    delay(100);
  }
}
void pedestrianMode() {
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW); 
  Serial.print("Time: ");
  Serial.print(millis()); 
  Serial.println(" ms | State: PEDESTRIAN - FORCED RED");
  delay(8000); 
}