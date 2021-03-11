#ifndef LEDLIGHT_HPP
#define LEDLIGHT_HPP

#include <Arduino.h>


class LEDLight
{
    public:
        LEDLight()
        {
            pinMode(GREEN_LED, OUTPUT);
            pinMode(RED_LED, OUTPUT);
        }

        void Green_LED(int state);
        void Red_LED(int state);


    private:
        const int GREEN_LED = 3;
        const int RED_LED   = 2;
};

#endif  //-- LEDLIGHT_HPP