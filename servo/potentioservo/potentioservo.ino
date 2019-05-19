#include <Gamebuino-Meta.h>
#include <Servo.h>
 
int servoPin = A3; // I use pin A3 from the backpack
int angle = 0;   // servo position in degrees 
Servo servo;  

void setup() {
    gb.begin();
    // use pin A1 as an input
    pinMode(A1, INPUT);
    // defines the pin used to control the servo
    servo.attach(servoPin); 
}

void loop() {
    while (!gb.update());
    gb.display.clear();

    // read the input on analog pin A1:
    int sensorValue = analogRead(A1);
    // convert it to a value between 0 and 180
    int angle = map(sensorValue, 0, 1023, 0, 180);
    servo.write(angle);
    gb.display.setColor(WHITE);
    gb.display.setFontSize(4);
    gb.display.print(8, 8, angle);    
}