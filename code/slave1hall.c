#include <Wire.h>

// Include the required Wire library for I2C<br>#include 
int x = 1;
void setup() {
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(3, OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
   pinMode(8,OUTPUT);
  pinMode(A1,INPUT);
  // Start the I2C Bus as Master
  Wire.begin(); 
}
int in=0;
void loop() {
   int valor = analogRead(1);
    
  Serial.println(valor);
  digitalWrite(8, valor >= 400 ? HIGH : LOW);
  int sensorValue=analogRead(0);
  sensorValue= ((sensorValue*3/1024)-0.5)*100;
 
   delay(10);
  if(sensorValue>40)
    {
  Wire.beginTransmission(9); // transmit to device #9
  x=1;
    Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  }
  else
  {Wire.beginTransmission(9); // transmit to device #9
  x=4;
   Wire.write(x);              // sends x 
  Wire.endTransmission();
  }
  int i=250;
    analogWrite(3, i);
  	digitalWrite(4,HIGH);
 
  if(in>10)
  {
    analogWrite(2,i);
    digitalWrite(5,HIGH);
  } 
  else if(in==0)
  {
    analogWrite(3, 0);
  	digitalWrite(4,LOW);
    
  }
  else if(in<10)
  {
    analogWrite(2,0);
    digitalWrite(5,LOW);
  }
  int it=digitalRead(6);
  delay(500);
  int ot=digitalRead(7);
  if(it==1)
    in=in+1;
  if(ot==1)
   in=in-1;
  
}
