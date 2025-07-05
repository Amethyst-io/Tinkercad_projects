float temp;
float vout;
float vout1;
const int LED = 13;
int gasSensor;
const int piezo = 7;

void setup()
{
  pinMode (A0,INPUT);
  pinMode (A1,INPUT);
  pinMode (LED,OUTPUT);
  pinMode (piezo,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  vout=analogRead(A0);
  vout1=(vout/1023.0)*5000;
  temp=(vout1-500)/10;
  gasSensor=analogRead(A1);

  digitalWrite(LED, temp >= 80 ? HIGH : LOW);

  digitalWrite(piezo, gasSensor >= 100 ? HIGH : LOW);

  Serial.print("Temp(°C): ");
  Serial.print(temp);
  Serial.print("\tGas: ");
  Serial.print(gasSensor);
  Serial.println();

  delay(1000);
}
