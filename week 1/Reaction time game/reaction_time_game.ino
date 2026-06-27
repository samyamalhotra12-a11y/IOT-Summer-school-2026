const int redLED = 8;
const int yellowLED = 9;
const int greenLED = 10;
const int buttonPin = 2;
unsigned long startTime;
unsigned long reactionTime;
void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("=== Reaction Time Game ===");
  Serial.println("Wait for the GREEN LED and press the button!");
}
void loop() {
  digitalWrite(redLED, LOW);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
  delay(2000);
  for (int i = 0; i < 6; i++) {
    int randomLED = random(3);
    if (randomLED == 0) {
      digitalWrite(redLED, HIGH);
    }
    else if (randomLED == 1) {
      digitalWrite(yellowLED, HIGH);
    }
    else {
      digitalWrite(greenLED, HIGH);
    }
    delay(random(300, 1000));
    digitalWrite(redLED, LOW);
    digitalWrite(yellowLED, LOW);
    digitalWrite(greenLED, LOW);
    delay(random(200, 700));
  }
  digitalWrite(greenLED, HIGH);
  startTime = millis();
  while (digitalRead(buttonPin) == LOW) {
  }
  reactionTime = millis() - startTime;
  digitalWrite(greenLED, LOW);
  Serial.print("Your Reaction Time: ");
  Serial.print(reactionTime);
  Serial.println(" ms");
  delay(3000);
}
  
