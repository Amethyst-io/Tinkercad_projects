#include <Keypad.h>

const byte ROWS = 4;  // Keypad rows
const byte COLS = 4;  // Keypad columns

const int redLed= 10;    // LED for access denied
const int greenLed =11;  // LED for access granted
const int piezo = 12;    // Buzzer pin

// Keypad layout (4x4 matrix)
char numPad[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};  // Connect to keypad rows
byte colPins[COLS] = {5, 4, 3, 2};  // Connect to keypad columns


String password = "6653";
String input = "";         // Stores user input

Keypad myKeypad = Keypad(makeKeymap(numPad), rowPins, colPins, ROWS, COLS);

void setup() {
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(piezo, OUTPUT);
  
  digitalWrite(redLed, HIGH);  // Start in locked state
  digitalWrite(greenLed, LOW);
  
  Serial.begin(9600);
  Serial.println("Enter Password: ");  // Initial prompt
}

void loop() {
  char key = myKeypad.getKey();  // Read pressed key
  
  if (key) {
    if (input.length() < 4) {     // Limit to 4 characters
      Serial.print('*');          // Mask input
      input += key;               // Add key to input string
    }
  }
  
  if (input.length() == 4) {     // When 4 digits entered
    delay(500);                  // Short debounce delay
    
    if (input == password) {      // Correct password
      grantAccess();
    } else {                      // Wrong password
      denyAccess();
    }
    
    resetSystem();  // Prepare for next attempt
  }
}

void grantAccess() {
  Serial.println("\nAccess Granted!");
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
  tone(piezo, 500, 100);  // Short beep -tone(pin, freq, duration)
  delay(1000);  // Hold success state
}

void denyAccess() {
  Serial.println("\nAccess Denied!");
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, LOW);
  
  // Double beep pattern
  tone(piezo, 1000, 300);
  delay(500);
  tone(piezo, 1000, 300);
  delay(1000);
}

void resetSystem() {
  input = "";  // Clear input buffer
  digitalWrite(redLed, HIGH);  // Return to locked state
  digitalWrite(greenLed, LOW);
  Serial.println("\nEnter Password: ");  // New prompt
}