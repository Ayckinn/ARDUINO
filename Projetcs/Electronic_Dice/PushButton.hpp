#ifndef _BUTTON_HPP_
#define _BUTTON_HPP_

#include <Arduino.h>

#define BUTTON_PIN 12


class PushButton
{
    public:

        PushButton() { pinMode(BUTTON_PIN, INPUT); }

        int buttonState()
        {
            return readButtonState();
        }


    private:

        int readButtonState()
        {
            int pushButtonState = digitalRead(BUTTON_PIN);
            return pushButtonState;
        }
};

#endif //-- _BUTTON_HPP_