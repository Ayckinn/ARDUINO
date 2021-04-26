////////////////////////////////// LIBRARIES //////////////////////////////////
#include "../header/ServoSG90.hpp"
#include "../header/USonic_HC-SR04.hpp"

/////////////////////////////// OBJECT CREATION ///////////////////////////////
ServoSG90::ServoSG90() {}
Servo sg90;
USonicHCSR04 sr04;

/////////////////////////////////// METHODS ///////////////////////////////////
void ServoSG90::ServoIgnition()
{
    sg90.attach(SERVO_PIN);
    //-- Initial position of servo 
    sg90.write(0);
}
/*---------------------------------------------------------------------------*/
void ServoSG90::ServoMoveForward()
{   
    for(int x = 0; x <= 180; ++x)
    {
        sg90.write(x);
        delay(30);

        sr04.GetSoundWavesData();

        //-- /!\ NO PRINTLN !! 
        //-- Otherwise, UI software will not be able to read datas in the monitor
        Serial.print(x);
        Serial.print(F("*"));
        Serial.print(sr04.distance);
        Serial.print(F("#"));
    }
}
/*---------------------------------------------------------------------------*/
void ServoSG90::ServoMoveBack()
{
    for(int x = 180; x >= 0; --x)
    {
        sg90.write(x);
        delay(30);

        sr04.GetSoundWavesData();

        Serial.print(x);
        Serial.print(F("*"));
        Serial.print(sr04.distance);
        Serial.print(F("#"));
    }
}
/*--- TessBarAnn ---*/