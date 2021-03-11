/*
|| AUTHOR    : Ayckinn
|| COPYRIGHT : ©2021
|| PROGRAM   : RFID Control Access
|| VERSION   : 1.0
||
|| ============================== SPECIFICATIONS ==============================
|| Eléments : 
||  - RFID-RC522 
||  - LCD 16x2
||  - Servomoteur SG90
||  - Potentiometre 
||  - LED
||
|| ========================= CE QUE FAIT LE PROGRAMME =========================
|| L'utilisateur scanne sa carte NFC, si elle est reconnue :
|| - la LED verte s'allume et la porte s'ouvre
|| sinon, la LED rouge s'allume et la porte reste fermée.
*/
////////////////////////////////// LIBRAIRIES /////////////////////////////////
#include <Arduino.h>

#include "../header/RFID_RC522.hpp"
#include "../include/RFID_RC522.cpp"

#include "../header/ServoSG90.hpp"
#include "../include/ServoSG90.cpp"

#include "../header/LCD16x2.hpp"
#include "../include/LCD16x2.cpp"

#include "../header/LEDLight.hpp"
#include "../include/LEDLight.cpp"

/////////////////////////////// APPEL DE CLASSE ///////////////////////////////
RC522_RFID mrc522;
ServoSG90 servo_sg90;
LCD16x2 lcd16x2;

//////////////////////////////// START PROGRAM ////////////////////////////////
void setup() 
{
    Serial.begin(115200);
    Serial.println("Serial OK");

    mrc522.Ignition();

    servo_sg90.ServoIgnition();

    lcd16x2.DisplayLogo();
    lcd16x2.DisplayWaitUID();    
}

void loop()
{
    mrc522.WaitScanUID();
    mrc522.ReadUID();
}

///////////////////////////////// STOP PROGRAM ////////////////////////////////
/*--- TessBarAnn ---*/