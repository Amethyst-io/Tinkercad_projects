int potPin = A0;  //Declare potpin to be analog pin A0
int LEDPin = 9;   //Declare LEDPin to be arduino pin 9
int readValue;    //Use this variable to read Potentiometer
int writeValue;   //Use this variable for writing to LED

void setup()
{
  pinMode (potPin, INPUT);  //set potPin to be an input
  pinMode (LEDPin, OUTPUT); //set LEDPin to an OUTPUT
  Serial.begin(9600);       //turn on Serial Port
}

void loop()
{
  readValue= analogRead(potPin);  //Read the voltage on the Potentiometer
  writeValue = (255./1023.) *readValue;  //Calculate Write Value
       // upper command takes a range of values from 0 to 1023
  analogWrite(LEDPin, writeValue);   //WWrite to the LED
  Serial.print("You are writing a value of ");  //Write to the LED
  Serial.println(writeValue);
  
}