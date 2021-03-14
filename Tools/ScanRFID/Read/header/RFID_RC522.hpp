#ifndef RFID_RC522_HPP
#define RFID_RC522_HPP

#include <Arduino.h>
#include <MFRC522.h>  //-- Andreas Balboa
#include <MFRC522Extended.h>
//-- For communication between several devices (Here : RFID & LCD)
//-- To avoid an error , add them at the 'lib deps' line in 'platformio.ini
#include <SPI.h>
#include <Wire.h>

//////////////////////////// ARDUINO INPUTS/OUTPUTS ///////////////////////////
 /*
 * Connection order by cards - IN THIS ORDER !! :
 * +-----------+-----------+-------------+--------+--------+----------------+-----------+
 * |  Signal   |  MFRC522  |     Uno     |  Mega  |  Nano  | Leonardo/Micro | Pro Micro |
 * |-----------+-----------+-------------+--------+--------+----------------+-----------|
 * | RST/Reset | RST       | 9           |  5     | D9     | RESET/ICSP-5   | RST       |
 * | SPI SDA   | SS(SDA)   | 10          | 53     | D10    | 10             | 10        |
 * | SPI MOSI  | MOSI      | 11 / ICSP-4 | 51     | D11    | ICSP-4         | 16        |
 * | SPI MISO  | MISO      | 12 / ICSP-1 | 50     | D12    | ICSP-1         | 14        |
 * | SPI SCK   | SCK       | 13 / ICSP-3 | 52     | D13    | ICSP-3         | 15        |
 * +-----------+-----------+-------------+--------+--------+----------------+-----------+
 *///-- Must be on these pins, coded to these numbers in the library
const int SDA_PIN   = 10;
const int RESET_PIN =  9;

MFRC522 rc522(SDA_PIN, RESET_PIN);
MFRC522Extended rc522Ext;
MFRC522::MIFARE_Key key;
MFRC522::StatusCode status;


class RFID_RC522
{
    private:
        String hexaCode[63]; 
        //-- 16 rows - 4 columns
        byte hexa_table[16][4] = 
        {
            { 0,  1,  2,  3},
            { 4,  5,  6,  7},
            { 8,  9, 10, 11},
            {12, 13, 14, 15},
            {16, 17, 18, 19},
            {20, 21, 22, 23},
            {24, 25, 26, 27},
            {28, 29, 30, 31},
            {32, 33, 34, 35},
            {36, 37, 38, 39},
            {40, 41, 42, 43},
            {44, 45, 46, 47},
            {48, 49, 50, 51},
            {52, 53, 54, 55},
            {56, 57, 58, 59},
            {60, 61, 62, 63}
        };
        byte buffer[18];
        byte size = sizeof(buffer);
        byte block = 7;
        
        int varSector = 1;

        MFRC522::PICC_Type hexaPiccType;
        MFRC522::PICC_Type dumpPiccType;
        // String home_tag_int = "57 112 250 191";
        // String home_tag_hex = "39 70 FA BF";


    public:
        RFID_RC522();

        void Ignition();
        void SelfTest();
        void DisplayFirmwareVersion();
        void WaitScanModule();
        void DumpModule();
        
        void DisplayHexUID();
        void DisplayIntUID();
        void DisplayProductModel();
        void DisplaySAK();
        void DisplayManufacturer();
        void DisplayHexaTable();
        void DisplayDumpReadError();
};

#endif  //-- RFID_RC522_HPP

/*--- TessBarAnn ---*/