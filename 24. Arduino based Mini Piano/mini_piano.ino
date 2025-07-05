#define T_C 262 //Frequencies of different keys
#define T_D 294
#define T_E 329
#define T_F 392
#define T_G 440
#define T_A 493
#define T_B 523

const int C = 2; // Connect to the pins of the Arduino
const int D = 4;
const int E = 6;
const int F = 7;
const int G = 9;
const int A = 11;
const int B = 12;

const int Buzz = 13;

void setup()
{
  // Set pins as input with internal pull-up resistors enabled
  pinMode(C, INPUT_PULLUP);
  pinMode(D, INPUT_PULLUP);
  pinMode(E, INPUT_PULLUP);
  pinMode(F, INPUT_PULLUP);
  pinMode(G, INPUT_PULLUP);
  pinMode(A, INPUT_PULLUP);
  pinMode(B, INPUT_PULLUP);
}

void loop()
{
  while(digitalRead(C) == LOW)
  {
    tone(Buzz, T_C);  //To get the desired tone from the speaker
  }
  
  while (digitalRead(D) == LOW)
  {
    tone(Buzz, T_D);
  }
         
  while (digitalRead(E) == LOW)
  {
    tone(Buzz, T_E);
  }
    
  while (digitalRead(F) == LOW)
  {
    tone(Buzz, T_F);
  }
  while (digitalRead(G) == LOW)
  {
    tone(Buzz, T_G);
  }
         
  while (digitalRead(A) == LOW)
  {
    tone(Buzz, T_A);
  }
    
  while (digitalRead(B) == LOW)
  {
    tone(Buzz, T_B);
  }
  noTone(Buzz);
        
}
         
// Notes for twinkle twinkle little star
         /*
         CC GG AA G
         FF EE D D C
         G GF F E E D
         GG FF EE D
         CC GG AA G
         FF EE D D C
         */