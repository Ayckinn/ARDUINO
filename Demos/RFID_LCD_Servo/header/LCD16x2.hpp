#ifndef LCD16X2_HPP
#define LCD16X2_HPP

#include <Arduino.h>
#include "LiquidCrystal.h"  //-- By Arduino

//-- LCD pins -> Arduino pins
const int RS = 12;
const int EN = 11;
const int D7 = 10;
const int D6 =  9;
const int D5 =  8;
const int D4 =  7;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


class LCD16x2
{
    public:
        LCD16x2()
        {
            lcd.begin(16, 2);
        }

        void DisplayLogo();
        void DisplayWaitUID();
        void AccessOK(String name);
        void AccessDenied();


    private:
        //-- PASS
};

#endif  //-- LCD16X2_HPP
/*--- TessBarAnn ---*/