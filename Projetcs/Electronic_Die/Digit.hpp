#ifndef _DIGIT_HPP_
#define _DIGIT_HPP_

#include <Arduino.h>
#include "PushButton.hpp"

PushButton pushBTN;

/*
      3
      _
  7 | 8 | 2
      _ 
  6 |   | 4
      _
      5
*/

/*--------------------------*/
/*-- LOOPS INITIALISATION --*/
/*--------------------------*/
#define segInit() for(int seg(2); seg <= 9; ++seg)
#define IAChoose() for(int x(1); x < 7; ++x)
#define animationLoop(xtimes) for(int y(0); y < xtimes; ++y)


class Digit
{
    int seg = 2;
    int randChoice = 0;
    

    public:

        Digit() { segInit() { pinMode(seg, OUTPUT); } }

        void test()
        {
            eight();
        }

        void letsPlay()
        {
            if(pushBTN.buttonState() == HIGH)
            {
                //-- Play animation before display number
                animationLoop(3) { animation(); }
                //-- IA choose number
                IAChoose() { randomChoice(); } 

                randChoice = randomChoice();

                switch(randChoice)
                {
                    case 1:
                        segmentOff();
                        one();
                        break;
                    case 2:
                        segmentOff();
                        two();
                        break;
                    case 3:
                        segmentOff();
                        three();
                        break;
                    case 4:
                        segmentOff();
                        four();
                        break;
                    case 5:
                        segmentOff();
                        five();
                        break;
                    case 6:
                        segmentOff();
                        six();
                        break;
                }
            }    
        }

    private:

        int randomChoice()
        {
            randChoice = random(1,7);
            return randChoice;
        }

        void segmentOff()
        {
            segInit() { digitalWrite(seg, LOW); }
        }

        void one()
        {
            digitalWrite(2, HIGH);
            digitalWrite(4, HIGH);
        }

        void two()
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(8, HIGH);
        }

        void three()
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(8, HIGH);
        }

        void four()
        {
            digitalWrite(2, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
        }

        void five()
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
        }

        void six()
        {
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
        }

        void seven()
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
        }

        void eight()
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(6, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
        }

        void nine()
        {
            digitalWrite(2, HIGH);
            digitalWrite(3, HIGH);
            digitalWrite(4, HIGH);
            digitalWrite(5, HIGH);
            digitalWrite(7, HIGH);
            digitalWrite(8, HIGH);
        }

        void animation()
        {
            segmentOff();
            six();
            delay(40);
            segmentOff();
            four();
            delay(40);
            segmentOff();
            nine();
            delay(40);
            segmentOff();
            one();
            delay(40);
            segmentOff();
            five();
            delay(40);
            segmentOff();
            eight();
            delay(40);
            segmentOff();
            three();
            delay(40);
            segmentOff();
            two();
            delay(40);
            segmentOff();
            seven();
            delay(40);
        }
};

#endif //-- _DIGIT_HPP_