#ifndef ULTRASONIC_HCSR04_HPP
#define ULTRASONIC_HCSR04_HPP

#include <Arduino.h>


class USonicHCSR04
{
    private:
        #define ECHO_PIN    7
        #define TRIGGER_PIN 8    


    public:
        USonicHCSR04();

        void HCSR04Ignition();
        void GetSoundWavesData();

        long duration;
        int  distance;
};

#endif  //-- ULTRASONIC_HCSR04_HPP
/*--- TessBarAnn ---*/