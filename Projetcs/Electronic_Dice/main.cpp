/*
  _AUTHOR    : Ayckinn
  _COPYRIGHT : ©2021
  _SKETCH    : Electronic dice
  _VERSION	 : 1.0

+--------------------------------------------+
| WHAT PROGRAM IS DOING                      |
|                                            |
| When the button is pressed                 |
| the dice display random number from 1 to 6 |
+--------------------------------------------+
*/

#include "Digit.hpp"

Digit digitActivity;

//////////////////////////////// START PROGRAM ////////////////////////////////
void setup() 
{
    Serial.begin(9600);
    randomSeed(analogRead(0));
}

void loop()
{
    digitActivity.letsPlay();
    //digitActivity.test();
}
///////////////////////////////// STOP PROGRAM ////////////////////////////////
/*--- TessBarAnn ---*/