/*
  Code inspired by KeyboardAndMouseControl
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
  - 3 circuits attached to A0, A1, A2

  The mouse movement is always relative. This sketch reads four pushbuttons, and
  uses them to set the movement of the mouse.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 12/12/22
  modified 14/12/22
*/

#include "Keyboard.h"
#include "Mouse.h"

// set pin numbers for the five channels
// using analogRead
const int up_down  = A0;
const int left_right = A1;
const int click = A2;

//set threshold values
//THRESHOLDS TO BE CHANGED
const int upThreshold = 10;
const int downThreshold = 10;
const int upDownMinThreshold = 10;
const int leftThreshold = 10;
const int rightThreshold = 10;
const int leftRightMinThreshold = 10;
//const int clickThreshold = 10;


void setup() {  // initialize the buttons' inputs:
  pinMode(up_down, INPUT);
  pinMode(left_right, INPUT);
  pinMode(click, INPUT);

  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {

  //read value of the analog input
  //v = analogRead(analogPin) //change this line?

  // use serial input to control the mouse:
  if (Serial.available() > 0) {
    char inChar = Serial.read();

    switch (inChar) {
      case 'u':
        // move mouse up
        Mouse.move(0, -40);
        break;
      case 'd':
        // move mouse down
        Mouse.move(0, 40);
        break;
      case 'l':
        // move mouse left
        Mouse.move(-40, 0);
        break;
      case 'r':
        // move mouse right
        Mouse.move(40, 0);
        break;
      case 'c':
        // perform mouse left click
        // use default library function https://www.arduino.cc/reference/en/language/functions/usb/mouse/mouseclick/
        Mouse.click(MOUSE_LEFT); 
        break;
    }
  }
  
  //using a range of voltages
  //voltage values will be calibrated
  //change the cases to muscle signal corresponding to movements
  //scroll up
  if (analogRead(up_down) > upThreshold)
  { 
    Keyboard.write('u'); 
  } 
  //scroll down
  else if (analogRead(up_down) > upDownMinThreshold) && (analogRead(up_down) < downThreshold){ 
    Keyboard.write('d'); 
  }

  //scroll left
  if (analogRead(left_right) > leftThreshold) 
  {
    Keyboard.write('l');
  } 
  //scroll right
  else if (analogRead(left_right) > leftRightMinThreshold) && (analogRead(left_right) < rightThreshold)
  { 
    Keyboard.write('r'); //scroll right
  }

  //click
  //check presence of signal
  //may need to be changed, use analogRead to prevent misintepretation of signal
  if (digitalRead(click) == HIGH) 
  { 
    Keyboard.write('c'); 
  } 


}


