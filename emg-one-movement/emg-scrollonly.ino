/*
  Controls the mouse with different muscle contractions
  to do movements below:
  - scroll up/down/left/right

  Circuits connected to pin A4

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

//set variable to read value from click circuit
int clickVal = analogRead(click);

//threshold to allow click
const int threshold = 40; //inner forearm threshold, TO BE CHANGED CORRESPONDING TO ELECTRODE PLACEMENTS

//conditioning
bool onOff = false; //set switch base case to OFF

void setup() 
{  
  // initialize the buttons' inputs:
  pinMode(click, INPUT);

  Serial.begin(9600);

  // initialize mouse control:
  Mouse.begin();
}

void loop() 
{
  if (clickVal > threshold) 
   { 
    onOff = true; //set switch to ON (true)
    //scroll();

    while (onOff) //while switch is ON (true), keep scrolling
    {

      //scroll right 
      Mouse.move(10, 0);

      //decide how fast mouse scrolls
      delay(50);

      if (clickVal > threshold) 
      {
        onOff = false;
        break;
      } 
      //break;
    }
  }
}


//////////////////////////////////////////////////
// void scroll(){
//   while (onOff) //while switch is ON (true)
//   { //keep scrolling
//     Mouse.move(10, 0); //right
//     delay(50);

//     if (click > baseVoltage) 
//     {
//       onOff = false;
//       break;
//     } 
//     break;
//   }
// }


