int flameSensor = 2;
int gasSensor = 3;

int led = 8;
int buzzer = 9;

void setup() {
  pinMode(flameSensor, INPUT);
  pinMode(gasSensor, INPUT);

  pinMode(led, OUTPUT);
  pinMode(buzzer, OUTPUT);

  digitalWrite(led, LOW);
  digitalWrite(buzzer, LOW);

  Serial.begin(9600);
}

void loop() {

  int flame = digitalRead(flameSensor);
  int gas = digitalRead(gasSensor);

  // Flame or Gas detected
  if (flame == LOW || gas == LOW) {

    Serial.println("Fire or Gas Detected!");

    unsigned long startTime = millis();

    while (millis() - startTime < 30000) { // 30 seconds

      digitalWrite(led, HIGH);
      digitalWrite(buzzer, HIGH);
      delay(300);

      digitalWrite(led, LOW);
      digitalWrite(buzzer, LOW);
      delay(300);
    }
  }

  else {
    digitalWrite(led, LOW);
    digitalWrite(buzzer, LOW);
  }
}