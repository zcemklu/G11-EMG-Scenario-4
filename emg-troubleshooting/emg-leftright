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

// set pin numbers for the circuits attached to A2, A3:
// using analogRead
const int leftArm = A0;
const int rightArm = A1;
const int leftBiceps = A2;
const int rightTriceps = A3;

//minimum threshold that corresponds to a muscle contraction
const int LArmThreshold = 5; //TO BE CHANGED
const int RArmThreshold = 10; //TO BE CHANGED
const int LBicepsThreshold = 30; //TO BE CHANGED
const int RTricepsThreshold = 10; //TO BE CHANGED

void setup() {  
  
  // initialize the buttons' inputs:
  pinMode(leftArm, INPUT);
  pinMode(rightArm, INPUT);
  pinMode(leftBiceps, INPUT);
  pinMode(rightTriceps, INPUT);

  //turn on serial port
  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  // print to help with troubleshooting/tracking
  //Serial.print("Left Arm: " );
  Serial.println(analogRead(leftArm));
  delay(100);
  
  // // print to help with troubleshooting/tracking
  // Serial.print("Right Arm: " );
  // Serial.println(analogRead(rightArm));
  // delay(100);
  
  // // print to help with troubleshooting/tracking
  // Serial.print("Left Biceps: " );
  // Serial.println(analogRead(leftBiceps));
  // delay(100);

  // print to help with troubleshooting/tracking
  // Serial.print("Right Biceps: " );
  // Serial.println(analogRead(leftBiceps));
  // delay(100);

  // Serial.print("Right Triceps: " );
  // Serial.println(analogRead(rightTriceps));
  // delay(200);

  //test code LEFT
  // read and using inputs from the click circuit to control mouse
  if (analogRead(leftArm) > LArmThreshold) 
  { 
    //Mouse.click(MOUSE_LEFT); 
    Mouse.move(-10,0);
  }
  
  //test code RIGHT
  // if (analogRead(leftBiceps) > LBicepsThreshold) 
  // { 
  //   //Mouse.click(MOUSE_LEFT); 
  //   Mouse.move(10,0);
  // }

  // if (analogRead(leftBiceps) > LBicepsThreshold) 
  // { 
  //   //Mouse.click(MOUSE_LEFT); 
  //   Mouse.move(-10,0);
  // }
  
  // if (analogRead(rightTriceps) > RTricepsThreshold) 
  // { 
  //   //Mouse.click(MOUSE_LEFT); 
  //   Mouse.move(10,0);
  // }

}



