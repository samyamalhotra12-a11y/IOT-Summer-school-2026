void setup(){
  Serial.BEGIN(9600);
  for (int i=1; i<=4; i++){
    for (int j=1; j<=3; j++){
      Serial.print("sensor(i,j)");
    }
    Serial.println();
  }
}
