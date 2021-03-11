#include "../header/LEDLight.hpp"

void LEDLight::Green_LED(int state)
{
    digitalWrite(GREEN_LED, state);
}

void LEDLight::Red_LED(int state)
{
    digitalWrite(RED_LED, state);
}