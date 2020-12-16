#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int sensorPulsePin = 12;
int sensorOutput = 13;

float echoTime = 0;

const float soundSpeedMps = 340;
const float soundSpeedMpus = 0.000340;

void setup() {
  lcd.begin(16, 2);
  delay(500);

  pinMode(sensorPulsePin, OUTPUT);
  digitalWrite(sensorPulsePin, LOW);
  pinMode(sensorOutput, INPUT);
  Serial.begin(9600);
  delay(100);
}

void loop() {
  TriggerUltrasonicPulse();
  echoTime = pulseIn(sensorOutput, HIGH);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(DistanceCalcs(echoTime));
  lcd.setCursor(0, 1);
  lcd.print(DistanceCalcs(echoTime) * 100);

  delay(500);
}

void TriggerUltrasonicPulse() {
  digitalWrite(sensorPulsePin, HIGH);
  delayMicroseconds(10);
  digitalWrite(sensorPulsePin, LOW);
}

float DistanceCalcs(float time_us) {
  return ((time_us * soundSpeedMpus) / 2);  
}
