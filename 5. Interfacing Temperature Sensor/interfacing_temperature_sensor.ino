int temp = A0;
int tempPin = A0;         // Analog pin connected to temperature sensor
float temp_celsius;
float voltage;
float analog_reading;
float temp_far;

void setup()
{
  pinMode(tempPin, INPUT);  //set temp sensor as input
  Serial.begin(9600);
}
void loop()
{
  analog_reading= analogRead(tempPin);
  Serial.print("Analog reading: ");  //read analog reading
  Serial.println(analog_reading);
  
  //converting analog reading to voltage
  voltage = analog_reading*5/1024;
    //we divided by 1024 as the analog reading from the data ppin is between 0 and 1024
    // 5 is because of 5 volts
  
  Serial.print("Voltage reading: ");  //display voltage
  Serial.println(voltage);
  
  //reading in celsius:
  //converting from 10 mv per degree with 0.5V offset
  temp_celsius =100 * (voltage - 0.5);
  Serial.println("Celsius reading:" + String(temp_celsius) + ("°C"));
  temp_far =(temp_celsius * 9/5) + 32;
  Serial.println("Fahrenheit reading:" + String(temp_far) + ("°F\n"));
  delay(3000); //give a delay of 3 seconds before repeating the loop
}