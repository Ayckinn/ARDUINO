#ifndef RFID_RC522_HPP
#define RFID_RC522_HPP

#include <Arduino.h>
#include <MFRC522.h>  //-- Andreas Balboa
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
MFRC522::MIFARE_Key key;


class RFID_RC522
{
    private:
        MFRC522::PICC_Type hexaPiccType;
        MFRC522::PICC_Type dumpPiccType;


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
