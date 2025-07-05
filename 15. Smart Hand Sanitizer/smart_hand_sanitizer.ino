#include <Servo.h>

const int trigPin= 7;  //Trigger Pin of Ultrasonic Sensor
const int echoPin= 6;  //Echo Pin of Ultrasonic Sensor

Servo Myservo;   //Create object Myservo of type Servo

void setup()
{
  Serial.begin(9600);  //Starting Serial Terminal
  
  myservo.attach(5);  //Signal Pin of servo 
  
  pinMode(trigPin, OUTPUT);  //Set the trig pin as output
  pinMode(echoPin, INPUT);   //Set the echo pin as input
  
  Serial.print("Distance = ");
  Serial.print("Measurement = ");
  delay(2000);
  
}

void loop()
{
  long duration, cm;  //declaring a variable
  
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);        //To keep the trig pin high for 10us
  digitalWrite(trigPin, LOW);
  
  
  duration = pilseIn(echoPin, HIGH);  //Taking input from echopin
  cm = microsecondsTocentimeters(duration);
  
  Serial.print("Distance = ");
  Serial.print(cm);
  Serial.print("cm");
  delay(100);
  
  if(cm <= 10)   //Distance should be less than 10cm
  {
    Myservo.write(0); //Neutral Position of shaft
  }
  else
  {
    Myservo.write(90);  //trun left
  }

  Serial.println();
  delay(100);
}