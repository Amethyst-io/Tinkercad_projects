//Use one 74HC595 to connect a CC/CA seven-segment display
//Remember : volt 3 - 6

//remove remarks if u r using CC 7-seg display

#define segDisplay CATHODE
#define d250 delay(250);

const int buttonPin = 0;
const int ledPin = 1;  // commmon pin

//pin 11 of 74HC595 (SHCP)
const int checkPin = 2;

const int clockPin = 2;   // SHCP pin of 74HC595 (clock)

//pin 11 of 74HC595 (STCP)
const int latchPin = 3;

//pin 14 of 74HC595 (DS)
const int dataPin = 4;

//digit pattern for a 7-segment display
const byte digit[]=
{  //Dgfedcba
  B00111111,  //0
  B00000110,  //1
  B01011011,  //2
  B00111111,  //3
  B01001111,  //4
  B01100110,  //5
  B01101101,  //6
  B00000000,  //OFF
  B01111111,  //8
};

void setup()
{
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(latchPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  
  #ifdef segDISPLAY
  digitalWrite(ledPin, LOW);
  #else
  digitalWrite(ledPin, HIGH);
  #endif
  
  LEDwrite(8);
  delay(1000);
  LEDwrite(7);
  d250;
  LEDwrite(0);
}

void LEDwrite(int data)
{
  //turn off the output of 74HC595
  digitalWrite(latchPin, LOW);
  
  //update data to output from 74HC595
  #ifdef segDISPLAY     
  //It's a CA LED invert num
  
  shiftOut(dataPin, clockPin, MSBFIRST, digit[data]);
  #else
  //It's a CC LED
  shiftOut(dataPin, clockPin, MSBFIRST, ~digit[data]);
  #endif
  
  //turn on the output of 74HC595
  digitalWrite(latchPin, HIGH);
}

int RND()
{
  int seed = 0;
  int digit =0;
  while (digit > 6 || digit <=0)
  {
    seed = (seed * 53) + 21;
    digit = seed % 6;
    randomSeed(analogRead(PB5));
    seed = random(50) + digit;
    digit += seed;
    }
    return digit;
               }
 void rollDice (int times)
               {
                 for(int i= 0; i< times; i++)
                 {
                   LEDwrite(1); d250;
                   LEDwrite(2); d250;
                   LEDwrite(3); d250;
                   LEDwrite(4); d250;
                   LEDwrite(5); d250;
                   LEDwrite(6); d250;
                   LEDwrite(5); d250;
                   LEDwrite(4); d250;
                   LEDwrite(3); d250;
                   LEDwrite(2); d250;
                 }
                 LEDwrite(1); d250;
               }
               
               void loop() {
                 int btn = 0;
                 btn = digitalRead(buttonPin);
                 if (btn == HIGH) {
                   LEDwrite(7); d250;
                   int digit = RND();
                   rollDice(2);
                   LEDwrite(7); d250;
                   if (digit==1) LEDwrite(1);
                   if (digit==2) LEDwrite(2);
                   if (digit==3) LEDwrite(3);
                   if (digit==4) LEDwrite(4);
                   if (digit==5) LEDwrite(5);
                   if (digit==6) LEDwrite(6);
                 }
               }