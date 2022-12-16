/*
  Controls the mouse with different muscle contractions
  to do movements below:
  - click

  Circuits connected to pin A4.

  Code inspired by KeyboardAndMouseControl https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 13/12/22
  edited 14/12/22

*/

#include "Mouse.h"

// set pin numbers for the circuits attached to A4:
// using analogRead
int click = A4;

//minimum threshold that corresponds to a muscle contraction
int threshold = 30; //TO BE CHANGED

void setup() {  
  
  // initialize the buttons' inputs:
  pinMode(click, INPUT);

  //turn on serial port
  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  // print to help with troubleshooting/tracking
  Serial.println(analogRead(click));
  delay(100);

  // read and using inputs from the click circuit to control mouse
  if (analogRead(click) > threshold) 
  { 
    Mouse.click(MOUSE_LEFT); 
  }

}


