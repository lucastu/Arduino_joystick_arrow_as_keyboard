#include "Keyboard.h"

const int buttonPin = 2;
const int analogPinX = A3
const int analogPinY = A4

int buttonState = 0;

void setup() {
  Keyboard.begin();
}

// KEY_UP_ARROW
// KEY_DOWN_ARROW
// KEY_LEFT_ARROW
// KEY_RIGHT_ARROW
// Keypad Enter is USB keycode 88 (0x58) but to get it through the Keyboard library unmapped you have to add 136 to it (0-127 is ascii and 128-135 are the 8 ctrl/shift/meta/option keys).
// After adding 136 you get 224 (0xE0). Use that with Keyboard.press() and Keyboard.release(), or Keyboard.write().

void loop() {
  //Bouton Enter
  buttonState = digitalRead(buttonPin);
  if ((buttonState != prevButtonState) && (buttonState == HIGH)) {
    Keyboard.write(KEY_UP_ARROW); 
  }
  prevButtonState = buttonState;
  //Fin bouton Enter
  
  valX = analogRead(analogPinX);
  valY = analogRead(analogPinY);
  treshold = 512;
  if (valX < treshold-10){
      Keyboard.write(KEY_LEFT_ARROW);  
      delay(100);
  }
  else if (valX > treshold+10){
      Keyboard.write(KEY_RIGHT_ARROW);
      delay(100);
  }
 
  if (valY < treshold-10){
      Keyboard.write(KEY_DOWN_ARROW); 
      delay(100);
  }
  else if (valY > treshold+10){
      Keyboard.write(KEY_UP_ARROW);  
      delay(100);
  }
}
