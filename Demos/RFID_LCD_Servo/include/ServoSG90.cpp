#include "../header/ServoSG90.hpp"

ServoSG90::ServoSG90() {}
Servo sg90;


void ServoSG90::ServoIgnition()
{
    sg90.attach(SERVO_PIN);
    //-- Servo starts at left (0° angle)
    CloseDoor();
}

/*---------------------------------------------------------------------------*/
void ServoSG90::OpenDoor()
{
    Serial.println("The door is opened, Servo angle : 90°");
    sg90.write(90);
}

/*---------------------------------------------------------------------------*/
void ServoSG90::CloseDoor()
{
    Serial.println("The door is closed, Servo angle : 0°");
    sg90.write(0);
}

/*--- TessBarAnn ---*/