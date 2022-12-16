/*
  Controls the mouse with different muscle contractions
  to do movements below:
  - scroll up
  - scroll down
  - scroll left
  - scroll right
  - click

  Circuits connected to pin A0, A1, A2, A3, A4.
  
  Code inspired by KeyboardAndMouseControl https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  To be used with Arduino Leonardo, Micro or Due.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 13/12/22
  edited 14/12/22
*/

#include "Mouse.h"

// set pin numbers for the circuits attached to A0, A1, A2, A3, A4:
//using analogRead
const int up  = A0;
const int down  = A1;
const int left = A2;
const int right = A3;
const int click = A4;

//minimum thresholds corresponding to different muscle contractions
const int upThreshold = 20; //checked - outer forearm
const int downThreshold = 40; //checked - inner forearm
const int leftThreshold = 30; //checked - biceps
const int rightThreshold = 70; //checked - triceps
const int clickThreshold = upBase; //checked - outer forearm //double up == click


void setup() {  
  
  // initialize the buttons' inputs:
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(click, INPUT);

  //turns on serial port
  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  // print to help with troubleshooting/tracking
  Serial.println(analogRead(click));
  delay(100);

  // read and using inputs from 5 circuits to control mouse
  //scroll up
  if (analogRead(up) > upThreshold) 
  { 
    Mouse.move(0, -10);
  }

  //scroll down
  if (analogRead(down) > downThreshold) 
  {
    Mouse.move(0, 10);
  } 

  //scroll left
  if (analogRead(left) > leftThreshold) 
  {
    Mouse.move(-10, 0);
  }

  //scroll right
  if (analogRead(right) > rightThreshold) 
  {
    Mouse.move(10, 0);
  }

  //click
  // use default library function https://www.arduino.cc/reference/en/language/functions/usb/mouse/mouseclick/
  if (analogRead(click) > clickThreshold) 
  {
    Mouse.click(MOUSE_LEFT); 
  }
  
}



