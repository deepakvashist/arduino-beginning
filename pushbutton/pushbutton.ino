int led = 2;
int button = 3;
int isButtonActive = 0;

void setup()
{
  pinMode(led, OUTPUT);
  pinMode(button, INPUT);
}

void loop()
{
  isButtonActive = digitalRead(button);

  if (isButtonActive == HIGH)
  {
    digitalWrite(led, HIGH);
    delay(5000);
  }
  else
  {
    digitalWrite(led, LOW);
  }
}
