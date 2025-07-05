const float baselineTem = 20.0;
const int sensorPin = A2;
const int redPin = 0;
const int bluePin = 1;
const int greenPin = 2;

float temp;

// Define colors as boolean arrays (R, G, B)
bool yellow[] = {1, 1, 0};
bool red[]    = {1, 0, 0};
bool green[]  = {0, 1, 0};
bool blue[]   = {0, 0, 1};
bool white[]  = {1, 1, 1};
bool cyan[]   = {0, 1, 1};
bool off[]    = {0, 0, 0};

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  pinMode(5, OUTPUT);      // Assuming pin 5 controls something else (e.g., power)
  digitalWrite(5, HIGH);  // Turn it on
}

void loop() {
  readSensor();
  colorConditions();
}

// Read sensor and convert to Celsius
void readSensor() {
  int sensorValue = analogRead(sensorPin);
  float voltage = sensorValue * 3.0 / 1024.0;
  temp = (voltage - 0.5) * 100.0;  // TMP36 sensor formula
}

// Control LEDs based on temperature
void colorConditions() {
  if (temp <= 9) {
    ledControlBlink(white);
  }
  else if (temp >= 35) {
    ledControlBlink(red);
  }
  else if (temp >= 10 && temp <= 14) {
    ledControl(white);
  }
  else if (temp >= 15 && temp <= 20) {
    ledControl(cyan);
  }
  else if (temp >= 21 && temp <= 24) {
    ledControl(green);
  }
  else if (temp >= 25 && temp <= 29) {
    ledControl(yellow);
  }
  else if (temp >= 30 && temp < 35) {
    ledControl(red);
  }
  else {
    ledControl(off);
  }
}

// Set LED colors
void ledControl(bool color[]) {
  digitalWrite(redPin, color[0]);
  digitalWrite(greenPin, color[1]);
  digitalWrite(bluePin, color[2]);
}

// Blink LEDs with given color
void ledControlBlink(bool color[]) {
  ledControl(color);
  delay(500);
  ledControl(off);
  delay(500);
}