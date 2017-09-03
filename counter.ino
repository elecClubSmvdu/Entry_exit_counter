/* Created by Ravi Prakash,
  on 3rd of sep,2017
  entry and exit counter..
 */
#include <LiquidCrystal.h> //Load Liquid Crystal Library
LiquidCrystal LCD(10, 9, 5, 4, 3, 2);  //Create Liquid Crystal Object called LCD

 
int Iread1;
int Iread2;
int ref=500;  // reference value for ir sensor

void setup()
{
pinMode(A0,INPUT);    // input from IR 1
pinMode(A1,INPUT);      // input from IR2
pinMode(13,OUTPUT);   // buzzer at pin 13
LCD.begin(16,2); 
}

void loop()
{
  int counter1;
  int counter2;
  int c2prev=0;
  int c1prev=0;
  Iread1=analogRead(A0);
  Iread2=analogRead(A1);
  if(Iread1<ref&&Iread2>ref&&c2prev==0)    // entry
  {
    counter1+=1;
    c1prev+=1;
    digitalWrite(13,HIGH);
    delay(20);
    digitalWrite(13,LOW);
    
  }
  if(Iread2<ref&&Iread1>ref&&c1prev==0)     // exit
  {
    counter2+=1;
    c2prev+=1;
    digitalWrite(13,HIGH);
    delay(20);
    digitalWrite(13,LOW);
  }
  if(Iread1<ref&&Iread2<ref)    // simultaneous
  {
    counter1+=1;
    counter2+=2;
    digitalWrite(13,HIGH);
    delay(20);
    digitalWrite(13,LOW);
    digitalWrite(13,HIGH);
    delay(20);
    digitalWrite(13,LOW);
  }
  LCD.setCursor(0,0); 
  LCD.print("Entries= ");
  LCD.print(counter1); 
  LCD.setCursor(0,1); 
  LCD.print("Exits= ");
  LCD.print(counter2); 
  
}

