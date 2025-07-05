//initialize pins
int analogPin = 0;       // Analog pin for voltage measurement
int chargePin = 8;       // Pin to charge capacitor
int dischargePin = 9;   // Pin to discharge capacitor

//initialize Resistor
int resistorValue = 1000;

//initialize Timer
unsigned long startTime;
unsigned long elapsedTime;

//Initialize Capacitance Variable
float microFarads;
float nanoFarads;

void setup()
{
  pinMode (chargePin, OUTPUT);
  digitalWrite(chargePin, LOW);
  Serial.begin(9600);  //Necessaary to print data to serial monitor over use
  Serial.println("Capacitance Measurement");  

}

void loop()
{
  digitalWrite(chargePin, HIGH);  //Begins charging the capacitor
  startTime = millis();            //Begins the timer
  
  // Wait until capacitor reaches 63.2% of 5V (647 = 1023 * 0.632)
  while(analogRead(analogPin) <647)  
  {
    //Does nothing until caapacitor reaches 63.2%of total voltage
  }
  
  unsigned long nowTime = millis();
  elapsedTime = nowTime -startTime; //Determine how much time it took to charge capacitor
  microFarads = ((float)elapsedTime / resistorValue) *1000;   // Calculate capacitance in microfarads (τ = R*C)
  Serial.print(elapsedTime);
  Serial.print("mS ");
  
  if (microFarads >1)  //Determine if units should be micro or nano and prints accordingly
  {
    Serial.print((long)microFarads);
    Serial.println("microFarads");
  }
  else
  {
    nanoFarads = microFarads * 1000.0;
    Serial.print((long)nanoFarads);
    Serial.println("nanoFarads");
    delay(500);
  }
  
  digitalWrite(chargePin, LOW);  // Stops charging capacitor
  pinMode(dischargePin, OUTPUT);
  digitalWrite(dischargePin, LOW);  //Allows capacitor to discharge
  while(analogPin > 0)
  {
    //Do nothing until capacitance is discharge
  }
  pinMode(dischargePin, INPUT);  //Prevents capacitor from discharging
}