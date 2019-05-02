#include <Wire.h>

// Include the required Wire library for I2C<br>#include 
int x = 2;
void setup() {
  pinMode(A0,INPUT);
  Serial.begin(9600);
  // Start the I2C Bus as Master
  Wire.begin(); 
}
void loop() {
  int sensorValue=analogRead(0);
  //float centi;//= ((sensorValue*5/1024)-0.5)*100;
 //Serial.println(centi);
  sensorValue= ((sensorValue*3/1024)-0.5)*100;
 Serial.println(sensorValue);
   delay(10);
  if(sensorValue>40)
    {
  Wire.beginTransmission(9); // transmit to device #9
  x=2;
    Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  }
  else
     {
  Wire.beginTransmission(9); // transmit to device #9
  x=5;
    Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  }
 Serial.println(x);
}
