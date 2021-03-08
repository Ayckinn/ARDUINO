#ifndef LEDS_HPP
#define LEDS_HPP

#include <Arduino.h>


class LEDS
{
    public:
        LEDS()
        {
            pinMode(GREEN_LED, OUTPUT);
            pinMode(RED_LED, OUTPUT);
        }

        void Green_LED(int state)
        {
            digitalWrite(GREEN_LED, state);
            return;
        }
        
        void Red_LED(int state)
        {
            digitalWrite(RED_LED, state);
            return;
        }


    private:
        const int GREEN_LED = 52;
        const int RED_LED   = 53;
};

#endif  //-- LEDS_HPP

/*--- TessBarAnn ---*/