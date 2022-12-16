/*
  Controls the mouse with different muscle contractions
  to do movements below:
  - scroll up/down/left/right

  Code inspired by KeyboardAndMouseControl https://www.arduino.cc/en/Tutorial/BuiltInExamples/KeyboardAndMouseControl

  WARNING: When you use the Mouse.move() command, the Arduino takes over your
  mouse! Make sure you have control before you use the mouse commands.

  created 14/12/22
  edited 16/12/22

*/

#include "Mouse.h"

// set pin numbers for the circuits attached to A0, A1, A2, A3, A4:
//using analogRead
const int up  = A0;
const int down  = A1;
const int left = A2;
const int right = A3;
const int click = A4;

//read values from each circuit
int upVal = analogRead(up);
int downVal = analogRead(down);
int leftVal = analogRead(left);
int rightVal = analogRead(right);
int clickVal = analogRead(click);

//threshold to allow click
const int upThreshold = 20; //checked - outer forearm
const int downThreshold = 40; //checked - inner forearm
const int leftThreshold = 30; //checked - biceps
const int rightThreshold = 70; //checked - triceps
const int clickThreshold = upThreshold; //checked - outer forearm //double up == click

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
  getMovement();
}


///////FUNCION TO GET WANTED MOVEMENT////////

void getMovement(){
  if (upVal > upThreshold) 
  { 
    scrollUp();
  }

  //scroll down
  if (downVal > downThreshold) 
  {
    scrollDown();
  } 

  //scroll left
  if (leftVal > leftThreshold) 
  {
    scrollLeft();
  }

  //scroll right
  if (rightVal > rightThreshold) 
  {
    scrollRight();
  }

  //click
  // use default library function https://www.arduino.cc/reference/en/language/functions/usb/mouse/mouseclick/
  if (clickVal > clickThreshold) 
  {
    leftClick();
  }

}


///////FUNCIONS FOR MOVEMENTS////////

void scrollUp()
{
  onOff = true; //set switch to ON (true)

    while (onOff) //while switch is ON (true), keep scrolling
    { 
      //move up
      Mouse.move(0, 10);

      //decide how fast mouse scrolls
      delay(50); 
      break;
    }
    onOff = false; //set switch to OFF 
    
    //next move
    getMovement();
}

void scrollDown()
{
  onOff = true; //set switch to ON (true)

    while (onOff) //while switch is ON (true), keep scrolling
    { 
      //move down
      Mouse.move(0, -10);

      //decide how fast mouse scrolls
      delay(50); 
      break;
    }
    onOff = false; //set switch to OFF 

    //next move
    getMovement();
}

void scrollLeft()
{
  onOff = true; //set switch to ON (true)

    while (onOff) //while switch is ON (true), keep scrolling
    { 
      //move left
      Mouse.move(-10, 0);

      //decide how fast mouse scrolls
      delay(50); 
      break;
    }
    onOff = false; //set switch to OFF 
  
    //next move
    getMovement();
}

void scrollRight()
{
  onOff = true; //set switch to ON (true)

    while (onOff) //while switch is ON (true), keep scrolling
    { 
      //move right
      Mouse.move(10, 0);

      //decide how fast mouse scrolls
      delay(50); 
      break;
    }
    onOff = false; //set switch to OFF 
  
    //next move
    getMovement();
}

void leftClick()
{
  Mouse.click(MOUSE_LEFT); 
}




