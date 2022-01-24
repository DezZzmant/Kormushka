/*
  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)
*/
#include <LiquidCrystal.h>
// The menu wrapper library
#include <LiquidMenu.h>
// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
/*
 * Variables used for periodic execution of code. The first one is the period
 * in milliseconds and the second one is the last time the code executed.
 */
unsigned int period_check = 1000;
unsigned long lastMs_check = 0;

unsigned int period_nextScreen = 5000;
unsigned long lastMs_nextScreen = 0;

LiquidLine Main_line_1(3, 1, "Hello Menu");
LiquidScreen Main_screen(Main_line_1, welcome_line2);

LiquidLine TimeSetup_line_1(0,0, "Time: ");
LiquidScreen TimeSetup_screen(TimeSetup_line_1);

LiquidMenu menu(lcd);
void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  menu.add_screen(Main_screen);
  menu.add_screen(TimeSetup_screen);
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  lcd.setCursor(0, 1);
  // print the number of seconds since reset:
  lcd.print(millis() / 1000);
}
