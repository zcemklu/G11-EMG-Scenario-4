/*
  Code inspired by KeyboardAndMouseControl
  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
  - 5 circuits attached to A0, A1, A2, A3, A4

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
// using analogReadconst 
const int up  = A0;
const int down = A1;
const int left = A2;
const int right  = A3;
const int click = A4;

//set threshold, assume all circuit has same threshold voltage
int threshold = 410;

void setup() {  // initialize the buttons' inputs:
  pinMode(up, INPUT);
  pinMode(down, INPUT);
  pinMode(left, INPUT);
  pinMode(right, INPUT);
  pinMode(click, INPUT);

  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
  Keyboard.begin();
}

void loop() {

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

  // use the 5 EMG circuits cases to control the keyboard:
  // this way a suppressor might be needed to make the choices to be binary
  //scroll up
  if (analogRead(up) > threshold) 
  { 
    Keyboard.write('u');
  }

  //scroll down
  if (analogRead(down) > threshold) 
  { 
    Keyboard.write('d');
  }

  //scroll left
  if (analogRead(left) > threshold) 
  { 
    Keyboard.write('l');
  }

  //scroll up
  if (analogRead(right) > threshold) 
  { 
    Keyboard.write('r');
  }

  //click  
  if (analogRead(click) > threshold) 
  { 
    Keyboard.write('c');
  }

}



