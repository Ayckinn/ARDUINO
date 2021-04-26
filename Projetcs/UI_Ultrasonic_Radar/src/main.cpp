/* ============================== DESCRIPTION ============================== *
    AUTHOR    : Ayckinn
    COPYRIGHT : ©2021 - Ayckinn Robotics
    PROGRAM   : UltraSonic Sonar
    VERSION   : 1.0

   =============================== CHANGELOG ===============================
    Version 1.0 - April 03' 2021
        - Initial Release

   ============================= SPECIFICATIONS ============================
    Products : HC-SR04 - Ultrasonic sensor
             : Servo SG90

   ========================== WHAT THE PROGRAM DOES ========================
    Radar scans the environment like a military radar, 
    when it detects an obstacle, the line detection takes the magenta color, 
    otherwise, the line is green
    
 * ========================================================================= */
////////////////////////////////// LIBRARIES //////////////////////////////////
#include <Arduino.h>

#include "../header/ServoSG90.hpp"
#include "../header/USonic_HC-SR04.hpp"

#include "../include/ServoSG90.cpp"
#include "../include/USonic_HC-SR04.cpp"

/////////////////////////////// OBJECT CREATION ///////////////////////////////
ServoSG90 servo_sg90;
USonicHCSR04 ultrasonic;

//////////////////////////////// START PROGRAM ////////////////////////////////
void setup() 
{
	Serial.begin(9600);

    ultrasonic.HCSR04Ignition();
    servo_sg90.ServoIgnition();
}
/*---------------------------------------------------------------------------*/
void loop()
{
	servo_sg90.ServoMoveForward();
    servo_sg90.ServoMoveBack();
}
///////////////////////////////// STOP PROGRAM ////////////////////////////////
/*--- TessBarAnn ---*/