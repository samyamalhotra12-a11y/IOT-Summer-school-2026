const int buzzer = 8;
const int dobtn = 3;
const int rebtn = 4;
const int mibtn = 5;
const int fabtn = 6;

void setup() {
  pinMode(dobtn, INPUT_PULLUP);
  pinMode(rebtn, INPUT_PULLUP);
  pinMode(mibtn, INPUT_PULLUP);
  pinMode(fabtn, INPUT_PULLUP);
}

void loop() {

  if (digitalRead(dobtn) == LOW)
    tone(buzzer,262);
  else if (digitalRead(rebtn) == LOW)
    tone(buzzer,294);
  else if (digitalRead(mibtn) == LOW)
    tone(buzzer,330);
  else if (digitalRead(fabtn) == LOW)
    tone(buzzer,349);
  else
    noTone(buzzer);}
