/*
|| AUTHOR    : Ayckinn
|| COPYRIGHT : ©2021
|| PROGRAM   : CHECK PASSWORD
|| VERSION   : 1.0
||
|| ============================== SPECIFICATIONS ==============================
|| Produits : LCD 16x2 - Keypad - Potentiometre - LED
||
|| ========================= CE QUE FAIT LE PROGRAMME =========================
|| L'utilisateur tape son mot de passe, s'il correspond à celui
|| qui est enregistré, a LED verte s'allume, sinon, la LED rouge s'allume
*/
////////////////////////////////// LIBRAIRIES /////////////////////////////////
#include <Arduino.h>

#include "../header/LCDScreen.hpp"
#include "../header/Leds.hpp"
#include "../header/KeypadModule.hpp"

#include "../include/LCDScreen.cpp"
#include "../include/Leds.cpp"
#include "../include/KeypadModule.cpp"

/////////////////////////////// APPEL DE CLASSE ///////////////////////////////
LCD_Screen lcdscreen;
Keypad_Module kpad;

//////////////////////////////// START PROGRAM ////////////////////////////////
void setup() 
{
    Serial.begin(9600);
    lcdscreen.Logo();
}

void loop()
{
    kpad.Check_Password();
}
///////////////////////////////// STOP PROGRAM ////////////////////////////////
/*--- TessBarAnn ---*/