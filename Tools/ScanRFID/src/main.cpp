/*
|| AUTHOR    : Ayckinn
|| COPYRIGHT : ©2021
|| PROGRAM   : Scan RFID
|| VERSION   : 1.0
||
|| ========================= WHAT THE PROGRAM'S DOING =========================
|| Allows to get UID from NFC module
*/
////////////////////////////////// LIBRARIES //////////////////////////////////
#include <Arduino.h>
#include <MFRC522.h>
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
const int SDA_PIN   = 53;
const int RESET_PIN =  5;

////////////////////////////////// CLASS CALL /////////////////////////////////
MFRC522 rc522(SDA_PIN, RESET_PIN);

/////////////////////////////////// METHODS ///////////////////////////////////
void DisplayRC522FirmwareVersion()
{
	// Get the RC522 firmware version
	byte firmware_version = rc522.PCD_ReadRegister(rc522.VersionReg);

	Serial.print(F("RC522 Firmware Version : 0x"));
	Serial.print(firmware_version, HEX);

	//-- Check version
	if (firmware_version == 0x91)
	{
	  	Serial.print(F(" = v1.0"));
	}
	else if (firmware_version == 0x92)
	{
	  	Serial.print(F(" = v2.0"));
	}
	else
	{
	  	Serial.println(F(" (Unknown)"));
	}

	// If 0x00 or 0xFF is returned, communication probably failed
	if ((firmware_version == 0x00) || (firmware_version == 0xFF))
	{
		Serial.println(F("---------------------------------------"));
		Serial.println(F("WARNING: Communication failure !"));
		Serial.println(F("Please, make sure the RC522 is connected..."));
	}
}
/*---------------------------------------------------------------------------*/
void RC522SelfTest()
{
    Serial.println(F("======================================="));
    Serial.println(F("==          RC522 SELF TEST          =="));
    Serial.println(F("=======================================\n"));

    DisplayRC522FirmwareVersion();

    Serial.println(F("---------------------------------------"));
    Serial.print(F("Test in progress... "));

    bool rc522_state = rc522.PCD_PerformSelfTest();
    
    if(rc522_state)
    {
        delay(2000);
        Serial.println(F("[Done]"));
        Serial.println(F("---------------------------------------"));
        Serial.print(F("RC522... "));
        delay(1000);
        Serial.println(F("[OK]"));
        Serial.println(F("---------------------------------------\n"));
        //-- Reset RC522 after test, otherwise, it will not scan anything
        rc522.PCD_Init();
    }
    else
    {
        Serial.println(F("[Failed]"));
        Serial.println(F("---------------------------------------"));
        Serial.print(F("RC522... "));
        Serial.println(F("[Not connected] or [Defect]"));
        Serial.println(F("---------------------------------------\n"));
        
        rc522.PCD_Init();
    }
}
/*---------------------------------------------------------------------------*/
void DisplayUID()
{
    //-- Get UID card or UID tag number : 
    //-- 1st group [0], 2nd group [1], 3rd group [2], 4th group [3], DEC = INT
    String UID_Card_Scanned = String(rc522.uid.uidByte[0], DEC) + " " +
                              String(rc522.uid.uidByte[1], DEC) + " " +
                              String(rc522.uid.uidByte[2], DEC) + " " +
                              String(rc522.uid.uidByte[3], DEC);

    Serial.print("UID tag : ");
    Serial.println(UID_Card_Scanned);
}

//////////////////////////////// START PROGRAM ////////////////////////////////
void setup() 
{
    Serial.begin(115200);
    Serial.println("\nTerminal communcation... [OK]\n");

    while(!Serial);    //-- Do nothing if no serial port opened
    SPI.begin();       //-- SPI bus ignition
    rc522.PCD_Init();  //-- RC522 module ignition
    
    RC522SelfTest();
}

void loop()
{
    //-- If no RFID module is present, return to the loop
    if(!rc522.PICC_IsNewCardPresent()) { return; }
    if(!rc522.PICC_ReadCardSerial())   { return; }

    //-- Dump info about the module - [PICC_HALTA()] is automatically called
    Serial.println("========================== RFID MODULE DETECTED : DETAILS ==========================");
    DisplayUID();
    rc522.PICC_DumpToSerial(&(rc522.uid));
}
///////////////////////////////// STOP PROGRAM ////////////////////////////////
/*--- TessBarAnn ---*/
