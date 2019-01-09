#include <LiquidCrystal.h> //Include the library that enables you to use the LCD
#include <SoftwareSerial.h>

int greenled = 6;
int yellowled = 7;
int redled = 8;
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
SoftwareSerial BlueTooth(10, 9); // (TXD, RXD) of HC-06
char BT_input; // to store input character received via BT.

void setup() {
lcd.begin(16,2);//16 by 2 are the dimensions of the LCD (in number of characters)
BlueTooth.begin(9600);//launch the process of receiving serial data (via bluetooth) at 9600 bits/s
pinMode(6, OUTPUT);
pinMode(7, OUTPUT);
pinMode(8, OUTPUT);
}

void loop() 
{
  if (BlueTooth.available())
 
  {
    BT_input=(BlueTooth.read());
    if (BT_input=='a')
    {
      lcd.clear();
      digitalWrite(greenled, HIGH);
      BlueTooth.println("Green LED is on");
      lcd.print("Green LED is on");
    }
    else if (BT_input=='b')
    {
      lcd.clear();
      digitalWrite(yellowled, HIGH);
      BlueTooth.println("Yellow LED is on");
      lcd.print("Yellow LED is on");
    }
   else if (BT_input=='c')
   {
    lcd.clear();
    digitalWrite(redled, HIGH);
    BlueTooth.println("Red LED is on");   
    lcd.print("Red LED is on");
   }
   else if (BT_input=='m')
   {
    digitalWrite(greenled, LOW);
    digitalWrite(yellowled, LOW);
    digitalWrite(redled, LOW);
    lcd.clear();
   }
   else
   {
    lcd.clear();
    lcd.print(BT_input);
   }
   // You may add other if else condition here. 
  }
}

//Before uploading the code to the Arduino, disconnect the Tx and Rx pins, otherwise you won't be able to upload. Once the code uploaded, reconnect them.
