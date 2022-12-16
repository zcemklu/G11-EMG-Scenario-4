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
//const int leftArm = A0;
// const int rightArm = A1;
// const int leftBiceps = A2;
// const int rightTriceps = A3;

//test pin
const int testPin = A0;

// using 1 circuit, 2 emg signals from 2 different muscle type, through same output pin
// used due to limited working EMG circuits
int testBiceps = analogRead(testPin)*0.5; //suppress signal strength to avoid interferance with other (testTriceps) threshold
int testTriceps = analogRead(testPin);

//minimum threshold that corresponds to a muscle contraction
const int LArmThreshold = 5; //TO BE CHANGED
const int RArmThreshold = 10; //TO BE CHANGED
const int LBicepsThreshold = 5; //TO BE CHANGED
const int RTricepsThreshold = 50; //TO BE CHANGED

void setup() {  
  
  // initialize the buttons' inputs:
  //pinMode(leftArm, INPUT);
  // pinMode(rightArm, INPUT);
  // pinMode(leftBiceps, INPUT);
  // pinMode(rightTriceps, INPUT);

  //initialise with test pin
  pinMode(testPin, INPUT);

  //turn on serial port
  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
}

void loop() {

  /////////////////////THRESHOLD VALUES TRACKING /////////////////////
  // tracks the change in signal value to help with troubleshooting

  //Serial.print("Left Arm: " );
  // Serial.println(analogRead(leftArm));
  // delay(50);
  
  // Serial.print("Right Arm: " );
  // Serial.println(analogRead(rightArm));
  // delay(100);
  
  // Serial.print("Left Biceps: " );
  // Serial.println(analogRead(leftBiceps));
  // delay(100);

  // Serial.print("Right Triceps: " );
  // Serial.println(analogRead(rightTriceps));
  // delay(100);

  // track with test pin actual signal strength
  Serial.println(analogRead(testPin));
  delay(100);

  /////////////////////TESTS/////////////////////
  
  //TEST 1 
  // read and using inputs from the click circuit to control mouse
  // moving electrode to fit testing
  // using 1 EMG circuit

  // test code for LEFT movement
  // if (analogRead(leftArm) > LArmThreshold) 
  // { 
  //   //Mouse.click(MOUSE_LEFT); 
  //   Mouse.move(-10,0);
  // }
  
  // test code for RIGHT movement
  // if (analogRead(leftBiceps) > LBicepsThreshold) 
  // { 
  //   //Mouse.click(MOUSE_LEFT); 
  //   Mouse.move(10,0);
  // }

  ///////////////////////////////////////////////////

  //TEST 2 
  // read and using inputs from the click circuit to control mouse
  // moving electrode to fit testing
  // using 1 EMG circuit

  // test code for LEFT movement
  // check signal from the test pin 
  // allow movement when signal is above left biceps threshold and below a limit to avoid interferance with other movements
  // if ((testBiceps > LBicepsThreshold) && (testBiceps < 20)) //eg. (15>5) && (15<20)
  // { 
  //   Mouse.move(-10,0);
  // }
  
  // test code for RIGHT movement
  // if (testTriceps > RTricepsThreshold) //eg. 70>50
  // { 
  //   //Mouse.click(MOUSE_LEFT); 
  //   Mouse.move(10,0);
  // }

  ///////////////////////////////////////////////////

  //TEST 3
  // read and using inputs from the click circuit to control mouse
  // moving electrode to fit testing
  // using 1 EMG circuit

  // test code for RIGHT movement
  // while (testBiceps > 20)
  // {
  //   Mouse.move(10,0);          
  // }

  // test code for LEFT movement
  // while (testBiceps < 20)
  // {
  //   Mouse.move(-10, 0);
  // }
  
  ///////////////////////////////////////////////////

  //TEST 4
  // read and using inputs from the click circuit to control mouse
  // moving electrode to fit testing
  // using 1 EMG circuit


  // if (analogRead(A0)>20){
  //   Mouse.move(10, 0); // test code for RIGHT movement
  // }
  // Mouse.move(-10, 0); // test code for LEFT movement


  /////////////////////ARCHIVES/////////////////////

  //
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



