#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);  //Initialize the LCD use I2C adress with 0x27, with 16 characters in 2 rows.

void setup() {
  lcd.init();         // Initialize the LCD
  lcd.clear();        // Clear any text from the LCD
  lcd.backlight();    // Turn on the LCD backlight

}

void loop() {
  // Display text on the first row
  lcd.setCursor(2, 0);
  lcd.print("Screen working");
  delay(1000);
  lcd.clear();

  // Display text on the second row
  lcd.setCursor(2, 1);
  lcd.print("Hello World!");
  delay(1000);
  lcd.clear();

}
