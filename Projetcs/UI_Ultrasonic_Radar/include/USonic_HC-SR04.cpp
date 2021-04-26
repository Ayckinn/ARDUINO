////////////////////////////////// LIBRARIES //////////////////////////////////
#include "../header/USonic_HC-SR04.hpp"

/////////////////////////////// OBJECT CREATION ///////////////////////////////
USonicHCSR04::USonicHCSR04() {}

/////////////////////////////////// METHODS ///////////////////////////////////
void USonicHCSR04::HCSR04Ignition()
{
    pinMode(ECHO_PIN, INPUT);
    pinMode(TRIGGER_PIN, OUTPUT);
}
/*---------------------------------------------------------------------------*/
void USonicHCSR04::GetSoundWavesData()
{
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    //-- Set the TRIGGER pin high for 10 microseconds
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);

    //-- Reads the ECHO pin & returns the time the sound wave travels in ms
    duration = pulseIn(ECHO_PIN, HIGH);
    //-- Calculate the distance
    distance = (duration * 0.034 / 2);
}
/*--- TessBarAnn ---*/