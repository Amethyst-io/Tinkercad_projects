#include <Servo.h>

Servo myservo;

#define trigPin 2
#define echoPin 3

float duration, distance;

void setup()
{
  myservo.attach(9);  // attaches the servo on pin 9
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop()
{
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);  // Fixed typo: 'pilseIn' -> 'pulseIn'

  // Determine distance from duration
  // Speed of sound = 343 m/s = 0.0343 cm/us
  distance = (duration / 2) * 0.0343;

  // Send results to Serial Monitor
  Serial.print("Distance = ");

  // Fixed 'If' to lowercase 'if' and corrected logic
  if (distance > 8 || distance < 2)  // Changed to proper range check
  {
    Serial.println("Out of range");
    myservo.detach();  // Detach servo to save power when out of range
  }
  else
  {
    Serial.print(distance);
    Serial.println(" cm");

    // Attach servo if detached
    if (!myservo.attached())
      myservo.attach(9);

    // Move servo to dispense sanitizer
    myservo.write(0);
    delay(1000);
    myservo.write(90);
    delay(1000);
    myservo.write(180);
    delay(1000);
    myservo.write(90);

    delay(500);
  }