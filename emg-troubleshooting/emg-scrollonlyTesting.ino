/*
  Controls the mouse with different muscle contractions
  to do movements below:
  - scroll up/down/left/right

  Code inspired by KeyboardAndMouseControl https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 13/12/22
  edited 14/12/22

*/

#include "Mouse.h"

//use dummy value
int click = 100;

//threshold to allow click
int threshold = 40; //checked, changed from 40

//conditioning
bool onOff = false; //set switch base case to OFF

void setup() {  
  // initialize the buttons' inputs:
  pinMode(click, INPUT);

  Serial.begin(9600);

  // initialize mouse and keyboard control:
  Mouse.begin();
}

void loop() 
{
   if (click > threshold) 
   { 
    onOff = true; //set switch to ON (true)

    while (onOff) //while switch is ON (true), keep scrolling
    { 
      //scroll right
      Mouse.move(10, 0);

      //decide how fast mouse scrolls
      delay(50); 
      break;
    }
  
  onOff = false; //set switch to OFF (false)
  click = 0; 
  }

  click = 100;
}



