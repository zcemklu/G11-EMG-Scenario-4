/*
  Simplified version of emg-v2
  Code inspired by KeyboardAndMouseControl https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  Controls the mouse from five pushbuttons on an Arduino Leonardo, Micro or Due.

  Hardware:
  - five pushbuttons attached to A0, A1, A2, A3, A4:

  The mouse movement is always relative. This sketch reads four pushbuttons, and
  uses them to set the movement of the mouse.

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 13/12/22

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl
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


void setup() 
{  // initialize the buttons' inputs:
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

void loop() 
{

  switch(analogRead(pin) > threshold)
  {
    case 'up':
      Mouse.move(0, -40);
    case 'down':
      Mouse.move(0, 40);
    case 'left':
      Mouse.move(-40, 0);
    case 'right':
      Mouse.move(40, 0);
    case 'click':
      Mouse.click(MOUSE_LEFT);
  }
  
}
