#ifndef SERVOSG90_HPP
#define SERVOSG90_HPP

#include <Arduino.h>
#include <Servo.h>


class ServoSG90
{
    private:
        #define SERVO_PIN 9


    public:
        ServoSG90();

        void ServoIgnition();
        void ServoMoveForward();
        void ServoMoveBack();
};

#endif  //-- SERVOSG90_HPP
/*--- TessBarAnn ---*/