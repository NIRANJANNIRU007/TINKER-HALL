#include <Wire.h>

// Include the required Wire library for I2C<br>#include 
int x = 3;
void setup() {
  pinMode(A0,INPUT);
  // Start the I2C Bus as Master
  Wire.begin(); 
}
void loop() {
  int sensorValue=analogRead(0);
  sensorValue = ((sensorValue*5/1024)-0.5)*100;
 Serial.println(sensorValue);
  if(sensorValue>-50)
    sensorValue=90;
  delay(10);
  if(sensorValue>80)
    {
  Wire.beginTransmission(9); // transmit to device #9
  x=3;
    Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  }
  else
     {
  Wire.beginTransmission(9); // transmit to device #9
  x=6;
    Wire.write(x);              // sends x 
  Wire.endTransmission();    // stop transmitting
  }
    
}
