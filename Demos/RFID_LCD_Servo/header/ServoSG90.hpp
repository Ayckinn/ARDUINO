#ifndef SERVO_SG90_HPP
#define SERVO_SG90_HPP

#include <Arduino.h>
#include <Servo.h>  //-- By Michael Margolis



class ServoSG90
{
    private:
        const int SERVO_PIN = 6;

        int servo_angle;


    public:
        ServoSG90();

        void ServoIgnition();
        void OpenDoor();
        void CloseDoor();
};


#endif  //-- SERVO_SG90_HPP
/*--- TessBarAnn ---*/