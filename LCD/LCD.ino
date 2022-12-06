#include <LiquidCrystal.h>

#define CONTRAST_PIN 6
#define CONTRAST_VALUE 100

#define ANIMATION_DELAY 32
#define PAUSE_DELAY 2000

#define LCD_WIDTH 16
#define LCD_HEIGHT 2
#define LCD_RS 7
#define LCD_EN 8
#define LCD_D4 9
#define LCD_D5 10
#define LCD_D6 11
#define LCD_D7 12

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7);

void setup()
{
  pinMode(CONTRAST_PIN, OUTPUT);
  analogWrite(CONTRAST_PIN, CONTRAST_VALUE);
  lcd.begin(LCD_WIDTH, LCD_HEIGHT);
}

void loop()
{
  AnimateContrast(CONTRAST_VALUE, 255);
  AnimateContrast(255, CONTRAST_VALUE);
  delay(PAUSE_DELAY);
  AnimateContrast(CONTRAST_VALUE, 0);
  AnimateContrast(0, CONTRAST_VALUE);
  delay(PAUSE_DELAY);
}

void AnimateContrast(int start, int end)
{
  int step = start < end ? 1 : -1;
  end += step;
  for (int contrast = start; contrast != end; contrast += step)
  {
    DisplayAndSetContrast(contrast);
  }
}

void DisplayAndSetContrast(int contrast)
{
  String text = "Contrast = ";
  text += contrast;
  lcd.home();
  lcd.setCursor((LCD_WIDTH - text.length()) / 2 - 1, 0);
  lcd.print(" " + text + " ");
  analogWrite(CONTRAST_PIN, contrast);
  delay(ANIMATION_DELAY);
}