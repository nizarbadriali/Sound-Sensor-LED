const int soundPin = 10;
const int ledPin   = 6;
const int holdTime = 10000;
unsigned long lastTrigger = 0;
const int cooldown = 4000;

void setup() {
  pinMode(soundPin, INPUT);
  pinMode(ledPin,   OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (digitalRead(soundPin) == HIGH && millis() - lastTrigger > cooldown) {
    Serial.println("Sound detected — LED on!");
    digitalWrite(ledPin, HIGH);
    lastTrigger = millis();
    delay(holdTime);
    digitalWrite(ledPin, LOW);
  }
  delay(100);
}
