#include <LiquidCrystal.h>

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

float vout = 0.0;
float vin = 0.0;
float R1 = 90900.0; // 90.9kΩ
float R2 = 10000.0; // 10kΩ
int analog_value = 0;

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.print("Digital voltmeter");
  delay(1500);
  lcd.clear();
}

void loop() {
  analog_value = analogRead(A0);
  vout = (analog_value * 5.0) / 1024.0; // Voltage at divider output
  vin = vout / (R2 / (R1 + R2));        // Input voltage calculation

  lcd.setCursor(0, 0);
  lcd.print("Voltage:        "); // Clear previous value
  lcd.setCursor(0, 1);
  lcd.print(vin, 2);             // Print with 2 decimal places
  lcd.print(" V      ");        // Clear trailing chars

  Serial.println(vin, 3);        // Print to Serial Monitor with 3 decimals

  delay(300);
}