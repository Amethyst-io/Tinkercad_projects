#include <Keypad.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

long first = 0;
long second = 0;
double total = 0;

char customKey;
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = 
{
  {'1','2','3','+'},
  {'4','5','6','-'},
  {'7','8','9','*'},
  {'C','0','=','/'}
};
byte rowPins[ROWS] = {7,6,5,4};  //connect to the row pinouts of
byte colPins[COLS] = {3,2,1,0};  //connect to the column pinouts

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


void setup()
{
  lcd.begin(16, 2);
  for(int i=0;i<=3;i++);
  lcd.setCursor(0,0);
  lcd.print("Calculator");
  lcd.setCursor(0,1);
  lcd.print("enter number");
  delay(4000);
  lcd.clear();
  lcd.setCursor(0, 0);
}
                             
void loop()
{
  customKey = customKeypad.getKey();
  switch(customKey)
  {
    case '0' ... '9':  //This keeps collecting the first value until
    lcd.setCursor(0,0);
    first = first*10 + (customKey - '0');
    //lcd.setCursor(0,1);
    lcd.print(first);
    break;
    
    case '+':
    first = (total != 0 ? total : first);
    //lcd.setCursor(0,1);
    lcd.print("+");
    second = SecondNumber(); //get the collected the second number
    total = first + second;
    lcd.setCursor(0,1);
    lcd.print(total);
    first = 0, second = 0;    //reset values back to zero for next
    break;
    
    case '-':
    first = (total != 0 ? total : first);
    //lcd.setcursor(0,1);
    lcd.print("-");
    second = SecondNumber();
    total = first - second;
    lcd.setCursor(0,1);
    lcd.print(total);
    first = 0, second = 0;
    break;
    
    case '*':
    first = (total != 0 ? total : first);
    //lcd.setcursor(0,1);
    lcd.print("*");
    second = SecondNumber();
    total = first * second;
    lcd.setCursor(0,1);
    lcd.print(total);
    first = 0, second = 0;
    break;
    
    case '/':
    first = (total != 0 ? total : first);
    //lcd.setcursor(0,1);
    lcd.print("/");
    second = SecondNumber();
    lcd.setCursor(0,1);
    
    second == 0 ? lcd.print("Invalid") : total = (float)first/second;
    
    lcd.print(total);
    first = 0, second = 0;
    break;
    
    case 'C':
    total = 0;
    lcd.clear();
    break;
  }
}
                             
long int SecondNumber()
{
  while(1)
  {
    customKey = customKeypad.getKey();
    
    if(customKey >= '0' && customKey <= '9' )
    {
      second = second*10+ (customKey - '0');
      lcd.setCursor(7,0);
      lcd.print(second);
    }
    if(customKey == '=') break; //return second;
  }
  return second;
}