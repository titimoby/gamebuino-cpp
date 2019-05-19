/* ----------------------------------------------------------
  Read analog value on aport
 Used in video Gamebuino 01 - Servomoteurs
 https://youtu.be/NQbfONUid2U
 ----------------------------------------------------------
 Author: TitiMoby
 Date: May 2019
---------------------------------------------------------- */
#include <Gamebuino-Meta.h>
#include <Servo.h>

#include <Servo.h> 
 
int servoPin = A3; // I use pin A3 from the backpack
int angle = 0;   // servo position in degrees 
Servo servo;  

void setup() {
  gb.begin();
  // defines the pin used to control the servo
  servo.attach(servoPin);
}

void loop() {
  // swipe from 30 to 150 degrees
  // depending on your physical servo, may work from 0 to 180
  for(angle = 30; angle < 150; angle++)  
  {                                  
    servo.write(angle);               
    delay(15);
  } 
  // now swipe back
  for(angle = 150; angle > 30; angle--)    
  {                                
    servo.write(angle);           
    delay(15); 
  }
}