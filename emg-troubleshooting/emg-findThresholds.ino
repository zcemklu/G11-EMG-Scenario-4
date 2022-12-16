/*
  Code to troubleshoot & find threshold values

  Circuits to be connected to pin A4

  Code inspired by KeyboardAndMouseControl https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 13/12/22
  edited 14/12/22

*/

#include "Mouse.h"

// set pin numbers for the circuits attached to A4:
// using analogRead
const int click = A4;

void setup() {  
  
  // initialize the buttons' inputs:
  pinMode(click, INPUT);

  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  // print to help with troubleshooting/tracking
  Serial.println(analogRead(click));
  delay(100);

}



