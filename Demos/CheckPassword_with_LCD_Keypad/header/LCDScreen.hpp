#ifndef LCDSCREEN_HPP
#define LCDSCREEN_HPP

#include <Arduino.h>
#include <LiquidCrystal.h>  //-- By Arduino

//-- LCD pins -> Arduino pins
const int EN = 45;
const int RS = 46;
const int D7 = 44;
const int D6 = 43;
const int D5 = 42;
const int D4 = 41;

LiquidCrystal lcd(RS, EN, D4, D5, D6, D7);


class LCD_Screen
{
    public:
        LCD_Screen()
        {
            lcd.begin(16, 2);
        }

        void Logo();
        void Pass_OK(String username);
        void Pass_NOK();


    private:
        //-- PASS
};

#endif  //-- LCDSCREEN_HPP
/*--- TessBarAnn ---*/