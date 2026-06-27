int led1=11;
int led2=9;
int led3=10;

void setup(){
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop(){
  analogWrite(led1, 50);
  delay(500);
  analogWrite(led1, 100);
  delay(500);
  analogWrite(led1, 150);
  delay(500);
  analogWrite(led1, 255);
  delay(500);
  
  analogWrite(led1,150);
  delay(500);
  analogWrite(led1, 100);
  delay(500);
  analogWrite(led1, 50);
  delay(500);
  analogWrite(led1, 0);
  delay(500);
  
  analogWrite(led2, 50);
  delay(500);
  analogWrite(led2, 100);
  delay(500);
  analogWrite(led2, 150);
  delay(500);
  analogWrite(led2, 255);
  delay(500);
  
  analogWrite(led2,150);
  delay(500);
  analogWrite(led2, 100);
  delay(500);
  analogWrite(led2, 50);
  delay(500);
  analogWrite(led2, 0);
  delay(500);
  
  analogWrite(led3, 50);
  delay(500);
  analogWrite(led3, 100);
  delay(500);
  analogWrite(led3, 150);
  delay(500);
  analogWrite(led3, 255);
  delay(500);
  
  analogWrite(led3,150);
  delay(500);
  analogWrite(led3, 100);
  delay(500);
  analogWrite(led3, 50);
  delay(500);
  analogWrite(led3, 0);
  delay(500);
}
  
  