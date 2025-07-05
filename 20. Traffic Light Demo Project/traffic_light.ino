/* this program blinks pin 13 of the Arduino 
   (The built in LED)
   */

int buttonState= 0;
const int buttonPin = 2;
int ledOne = 10;
int ledTwo = 11;
int ledThree = 12;
void setup()
{
  pinMode (ledOne, OUTPUT);
  pinMode (ledTwo, OUTPUT);
  pinMode (ledThree, OUTPUT);
  pinMode (buttonPin, INPUT);
  Serial.begin(9600);
}

void loop()
{
  buttonState = digitalRead(buttonPin);
  if(buttonState == 1)
  {
    digitalWrite(ledOne,1);
    Serial.print("STOP\n");
    delay(2000);
    digitalWrite(ledOne,0);
    delay(500);
    digitalWrite(ledTwo,1);
    Serial.print("GET READY\n");
    delay(2000);
    digitalWrite(ledTwo,0);
    delay(2000);
    digitalWrite(ledThree,1);
    Serial.print("GO\n");
    delay(2000);
    digitalWrite(ledThree,0);
  }
}