#include <LiquidCrystal.h>
//initialize the library with the numbers of the interface pin
LiquidCrystal lcd(0, 1, 2, 3, 4, 5);

void setup()
{
  //set up the LCD's number of columns and rows
  lcd.begin(16, 2);
  //print a message to the LCD
  lcd.print("This is me");
  //set the cursor to column 0, line 1
  //(note: line 1 is the second row, since counting begins with 
  lcd.setCursor(0, 1);
  //print my signature
  lcd.print("Amethyst");
}

void loop()
{
  //set the cursor to column 0, line 1
  lcd.setCursor(14, 1);
  //print time of seconds since start of the simulation
  lcd.print(millis() /1000);
  delay(100);  //delay to improve simulation performance
}