#include <DHT.h>


#define DHTPIN 4
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);


#define MQ2_PIN 34

#define RED_PIN 25
#define GREEN_PIN 26
#define BLUE_PIN 27
#define BUZZER 14

void setColor(bool r, bool g, bool b) {
  digitalWrite(RED_PIN, r);
  digitalWrite(GREEN_PIN, g);
  digitalWrite(BLUE_PIN, b);
}

void setup() {

  Serial.begin(115200);
  dht.begin();

  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);
  pinMode(BUZZER, OUTPUT);

  Serial.println("Timestamp, Gas(PPM), Temp(C), Humidity(%), Status");
}

void loop() {

  int gasRaw = analogRead(MQ2_PIN);

  int gasPPM = map(gasRaw, 0, 4095, 0, 5000);

  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  if (isnan(temp) || isnan(hum)) {
    Serial.println("DHT Error!");
    delay(2000);
    return;
  }

  String status;

  if (gasPPM < 1500) {

    status = "SAFE";

    setColor(LOW, HIGH, LOW);     
    noTone(BUZZER);

  }

  else if (gasPPM < 3000) {

    status = "MODERATE";

    setColor(HIGH, HIGH, LOW);

    tone(BUZZER, 1000);
    delay(200);
    noTone(BUZZER);

  }

  else {

    status = "DANGER";

    setColor(HIGH, LOW, LOW);     
    tone(BUZZER, 2000);

  }

  int sec = millis() / 1000;
  int min = sec / 60;
  sec %= 60;

  char timeStr[6];
  sprintf(timeStr, "%02d:%02d", min, sec);

  Serial.print(timeStr);
  Serial.print(", ");
  Serial.print(gasPPM);
  Serial.print(" ppm, ");
  Serial.print(temp);
  Serial.print(" C, ");
  Serial.print(hum);
  Serial.print("%, ");
  Serial.println(status);

  delay(2000);
}
