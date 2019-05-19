/* ----------------------------------------------------------
  Read analog value on aport
 Used in video Gamebuino 01 - Découverte de la console et premiers montages électroniques
 https://youtu.be/NQbfONUid2U
 ----------------------------------------------------------
 Author: TitiMoby
 Date: May 2019
---------------------------------------------------------- */
#include <Gamebuino-Meta.h>

void setup() {
  gb.begin();
  pinMode(A1, INPUT);
  SerialUSB.begin(9600);
  SerialUSB.println("start");
}

void loop() {
  while (!gb.update());
  gb.display.clear();
  
  // read the input on analog pin A1:
  int sensorValue = analogRead(A1);
  
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.3V)
  // max voltage mesured 3.8V fully charged but I added a protection resistor so, it's an almost
  float voltage = sensorValue * (3.3 / 1023.0);
  
  gb.display.setColor(WHITE);
  gb.display.setFontSize(4);
  gb.display.print(8, 8, sensorValue);
  
}
