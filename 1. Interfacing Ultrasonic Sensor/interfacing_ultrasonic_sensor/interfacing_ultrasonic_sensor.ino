//variable and pins declared and initialized
int trigPin = 10;
int echoPin = 9;
long time;
int distance;

void setup()
  //this loop repeats only once
{
  pinMode (10, OUTPUT); //TRIGpin set as output
  pinMode (9, INPUT);   // ECHO pin set as input
  Serial.begin(9600);   //begin communication
}

void loop()
  //this loop repeats continuously
{
  digitalWrite(10, LOW); //TRIG pin set LOW (cleared)
  delayMicroseconds(2);  // delay of 2 microseconds
  
  digitalWrite(10,HIGH);  //TRIG pin set as high(signal transmitter)
  delayMicroseconds(10);  //delay of 10 microseconds given
  digitalWrite(10,LOW);   //TRIG pin set as low again
  
  //calculating the distance
  time = pulseIn(9, HIGH);   //to calculate time of flight
  distance = time*0.034/2;  //to calculate distance of object
  
  //printing the distances
  Serial.print("Distance: ");
  Serial.println(distance);
}