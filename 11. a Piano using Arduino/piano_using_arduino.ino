int buttons[] = {2, 3, 4, 5, 6, 7, 8, 9};
int frequencies[] = {300, 400, 500, 600, 700, 800, 900, 1000};
int buzzer = 13;

void setup() {
  for (int i = 0; i < 8; i++) {
    pinMode(buttons[i], INPUT_PULLUP);  // Enable internal pull-up resistors
  }
  pinMode(buzzer, OUTPUT);
}

void loop() {
  bool tonePlayed = false;
  
  for (int i = 0; i < 8; i++) {
    if (digitalRead(buttons[i]) == HIGH) {  // Button pressed
      tone(buzzer, frequencies[i], 100);
      tonePlayed = true;
      break;  // Play only one tone at a time
    }
  }
  
  if (!tonePlayed) {
    noTone(buzzer);  // Stop buzzer if no button is pressed
  }
  
  delay(50);  // Small debounce delay
}