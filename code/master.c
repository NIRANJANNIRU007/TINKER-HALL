#include<Wire.h>
#include <LiquidCrystal.h>
int x;
const int rs = 11, en = 10, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
void setup() {
  Serial.begin(9600); 
  pinMode(8,OUTPUT);
  pinMode(12, OUTPUT);
pinMode(13, OUTPUT);
   lcd.begin(16, 2);
  lcd.print("Alarm Active.");// start serial for output
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);
}
void receiveEvent(int bytes) {
  x = Wire.read();    // read one character from the I2C
}
void loop() {
  
      
  // receive a byte as character
    
    lcd.setCursor(0, 1);
    lcd.print("Evacuate");// print the character
     delay(10);
      Serial.println(x);
    if(x==1)
    {
      lcd.setCursor(10, 1);
      lcd.print("1");
    }
    else if(x==2)
    {
      lcd.setCursor(11, 1);
      lcd.print("2");
    }
    else if(x==3)
    {
      lcd.setCursor(12, 1);
      lcd.print("3");
    }
    else if(x==4)
    {
      lcd.setCursor(10, 1);
      lcd.print("0");
    }
    else if(x==5)
    {
      lcd.setCursor(11, 1);
      lcd.print("0");
    }
    else if(x==6)
    {
      lcd.setCursor(12, 1);
      lcd.print("0");
    }
  
    if(x==1 || x==2 || x==3){// slave may send less than requested
      int notes[10]={261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
  //            mid C  C#   D    D#   E    F    F#   G    G#   A

   // Wait for 1000 millisecond(s)
  for(int i = 0; i < 10; i++){
    digitalWrite(13, HIGH);
   // Wait for 1000 millisecond(s)
  
  
    tone(12, notes[i]); //accesses spots on the array.
  }
    }
      else
      {
        digitalWrite(13, LOW);
      }
  
  

}
