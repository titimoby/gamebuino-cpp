/* ----------------------------------------------------------  
 Used in video Gamebuino 02 - Servomoteurs
 https://youtu.be/qcovLDaD41o

 Control servo position with a potentiometer or Gamebuino buttons
 ----------------------------------------------------------
 Author: TitiMoby
 Date: May 2019
---------------------------------------------------------- */
#include <Gamebuino-Meta.h>
#include <Servo.h>
 
int servoPin = A3; // I use pin A3 from the backpack
int angle = 0;   // servo position in degrees 
Servo servo;  
const int ANGLE_MAX = 170;
const int ANGLE_MIN = 10;

// defines the control mode, either potentiometer or thhrough Gamebuino buttons
enum controlMode {
    gamebuino,
    potentiometer
};
byte currentMode = potentiometer;

void setup() {
    gb.begin();    
    pinMode(A1, INPUT); // use pin A1 as an input
    servo.attach(servoPin);  // defines the pin used to control the servo
}

void loop() {
    while (!gb.update());
    gb.display.clear();

    // A/B choose between keys and potentiometer control
    if (gb.buttons.repeat(BUTTON_A, 0)) {
      currentMode = gamebuino;
    } else if (gb.buttons.repeat(BUTTON_B, 0)) {
      currentMode = potentiometer;
    }
    if (currentMode == potentiometer) {
      int sensorValue = analogRead(A1); // read the input on analog pin A1
      angle = map(sensorValue, 0, 1023, 0, 180); // convert it to a value between 0 and 180
    } else {
      if (gb.buttons.repeat(BUTTON_RIGHT, 0) && (angle < ANGLE_MAX)) {
        angle ++;
      } else if(gb.buttons.repeat(BUTTON_LEFT, 0) && (angle > ANGLE_MIN)) {
        angle--;
      }
    }
    servo.write(angle); // send angle to servo
    // some displays
    gb.display.setColor(WHITE);
    gb.display.setFontSize(4);
    gb.display.8print(8, 8, angle);
    gb.display.setFontSize(1);
    if (currentMode == potentiometer) {
      gb.display.print(4, 36, "Potentiometer");  
    } else {
      gb.display.print(4, 36, "Keys"); 
    }
}