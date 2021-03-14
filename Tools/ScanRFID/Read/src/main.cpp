/*
|| AUTHOR    : Ayckinn
|| COPYRIGHT : ©2021
|| PROGRAM   : Read RFID
|| VERSION   : 1.0
||
|| ========================= WHAT THE PROGRAM'S DOING =========================
|| Allows to get UID from NFC module
*/
////////////////////////////////// LIBRARIES //////////////////////////////////
#include <Arduino.h>

#include "../header/RFID_RC522.hpp"
#include "../include/RFID_RC522.cpp"

////////////////////////////////// CLASS CALL /////////////////////////////////
RFID_RC522 mrc522;

//////////////////////////////// START PROGRAM ////////////////////////////////
void setup() 
{
    Serial.begin(115200);
    Serial.println("\nTerminal communication... [OK]\n");

    while(!Serial);    //-- Do nothing if no serial port opened

    mrc522.Ignition();
    mrc522.SelfTest();
}

void loop() 
{ 
    mrc522.WaitScanModule();
    mrc522.DumpModule();
}
///////////////////////////////// STOP PROGRAM ////////////////////////////////
/*--- TessBarAnn ---*/