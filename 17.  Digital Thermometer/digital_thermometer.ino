#include <LiquidCrystal.h>  // Correct case

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int analogValue;
double voltage, celsius, fahrenheit;

void setup() {
  lcd.begin(16, 2);
  lcd.print("Today's Temp:");
}

void loop() {
  analogValue = analogRead(A0);  // Use A0 for clarity

  voltage = (analogValue * 5.0) / 1024.0;  // Convert ADC reading to voltage
  celsius = (voltage - 0.5) * 100.0;       // TMP36 sensor formula
  fahrenheit = (celsius * 9.0 / 5.0) + 32; // Convert to Fahrenheit

  lcd.setCursor(0, 1);
  lcd.print("                ");  // Clear second line (16 spaces)
  lcd.setCursor(0, 1);
  lcd.print(fahrenheit, 1);      // Print with 1 decimal place
  lcd.print((char)223);          // Degree symbol
  lcd.print("F");

  delay(1000);                   // Update every second
}