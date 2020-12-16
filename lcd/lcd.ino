#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

void setup()
{
  lcd.begin(16, 2);
  delay(500);
}

void loop()
{
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Hello world !!");
  lcd.setCursor(0, 1);
  lcd.print("Hello Deepak :)");

  delay(1000);
}
