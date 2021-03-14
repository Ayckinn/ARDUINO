#include "../header/RFID_RC522.hpp"

RFID_RC522::RFID_RC522() {}


void RFID_RC522::Ignition()
{
    //-- Bus SPI init
    SPI.begin();
    //-- RFID RC522 Module init
    rc522.PCD_Init();
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::SelfTest()
{
    Serial.println(F("======================================="));
    Serial.println(F("==          RC522 SELF TEST          =="));
    Serial.println(F("=======================================\n"));

    DisplayFirmwareVersion();

    Serial.println(F("---------------------------------------"));
    Serial.print(F("Test in progress... "));

    //-- Booleen to check if test has passed (true = 1) or failed (false = 0)
    bool rc522_state = rc522.PCD_PerformSelfTest();
    
    if(rc522_state)  //-- True
    {
        delay(1000);
        Serial.println(F("[Done]"));
        Serial.println(F("---------------------------------------"));
        Serial.print(F("RC522 Ignition...   "));
        delay(1000);
        Serial.println(F("[DONE]"));
        Serial.println(F("---------------------------------------"));
        Serial.println(F("--------- WAITING FOR UID SCAN --------"));
        Serial.println(F("---------------------------------------"));
        //-- Reset RC522 after test, otherwise, it will not scan anything
        rc522.PCD_Init();
    }
    else  //-- False
    {
        Serial.println(F("[FAILED]"));
        Serial.println(F("---------------------------------------"));
        Serial.print(F("RC522 Ignition... "));
        Serial.println(F("[Not connected] or [Defect]"));
        Serial.println(F("---------------------------------------\n"));
    }
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplayFirmwareVersion()
{
	// Get the RC522 firmware version
	byte firmware_version = rc522.PCD_ReadRegister(rc522.VersionReg);

	Serial.print(F("RC522 Firmware Version : 0x"));
	Serial.print(firmware_version, HEX);

	//-- Check version
    switch (firmware_version)
    {
        case 0x88:  Serial.println(F(" (CLONE)"));    break;
        case 0x90:  Serial.println(F(" (v0.0)"));     break;
        case 0x91:  Serial.println(F(" (v1.0)"));     break;
        case 0x92:  Serial.println(F(" (v2.0)"));     break;
        case 0x12:  Serial.println(F(" (FAKE)"));     break;
        default:    Serial.println(F(" (UNKNOWN)"));  break;
    }

	//If 0x00 or 0xFF is returned, communication probably failed
	if ((firmware_version == 0x00) || (firmware_version == 0xFF))
	{
		Serial.println(F("---------------------------------------"));
		Serial.println(F("WARNING: Communication failure !"));
		Serial.println(F("Please, make sure the RC522 is connected..."));
	}
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::WaitScanModule()
{
    //-- If no RFID module is present, return to the loop
    if(!rc522.PICC_IsNewCardPresent()) { return; }
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DumpModule()
{
    //-- If no module readed, reset loop
    if(!rc522.PICC_ReadCardSerial())   { return; }

    Serial.println("\n=== RFID MODULE DETECTED : DETAILS ===\n");

    DisplayHexUID();
    DisplayIntUID();
    DisplayProductModel();
    DisplaySAK();
    DisplayManufacturer();
    DisplayHexaTable();
    DisplayDumpReadError();

    Serial.println(F("\n\n--------------------------------------"));
    Serial.println(F("-------- WAITING FOR UID SCAN --------"));
    Serial.println(F("--------------------------------------"));
}

/*============================ INTERNAL FUNCTIONS ===========================*/
void RFID_RC522::DisplayHexUID()
{
    Serial.print(F("UID (Hexa code) :"));
    //-- 4 blocks of numbers
    for(byte x = 0; x < 4; ++x)
    {
        if(rc522.uid.uidByte[x] < 0x10) { Serial.print(F(" 0")); }
        else { Serial.print(F(" ")); }
        Serial.print(rc522.uid.uidByte[x], HEX);
    }
    Serial.println();
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplayIntUID()
{
    Serial.print(F("UID (Int code)  :"));
    for(byte x = 0; x < 4; ++x)
    {
        if(rc522.uid.uidByte[x] < 0x10) { Serial.print(F(" 0")); }
        else { Serial.print(F(" ")); }
        Serial.print(rc522.uid.uidByte[x], DEC);
    }
    Serial.println();
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplayProductModel()
{
    Serial.print(F("Product Info    : "));
    MFRC522::PICC_Type memorySize = rc522.PICC_GetType(rc522.uid.sak);
    Serial.println(rc522.PICC_GetTypeName(memorySize));
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplaySAK()
{
    Serial.print(F("SAK number      : "));
    if(rc522.uid.sak < 0x10) { Serial.print(F("0")); }
    Serial.println(rc522.uid.sak, HEX);
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplayManufacturer()
{
    Serial.print(F("Manufacturer    : "));
    if(rc522.uid.sak == 0x08) { Serial.print(F("NPX Semiconductors")); }
    if(rc522.uid.sak == 0x88) { Serial.print(F("Infineon")); }
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplayHexaTable()
{
    Serial.println(F("\n"));

    hexaPiccType = MFRC522::PICC_GetType(rc522.uid.sak);

    switch(hexaPiccType)
    {
		case rc522.PICC_TYPE_MIFARE_MINI:
		case rc522.PICC_TYPE_MIFARE_1K:
		case rc522.PICC_TYPE_MIFARE_4K:
			// All keys are set to FFFFFFFFFFFFh at chip delivery from the factory.
			for (byte i = 0; i < 6; i++) { key.keyByte[i] = 0xFF; }
            rc522.PICC_DumpMifareClassicToSerial(&(rc522.uid), hexaPiccType, &key);
        
        case rc522.PICC_TYPE_UNKNOWN:
		case rc522.PICC_TYPE_NOT_COMPLETE:
		default:
			break; // No memory dump here
    }
    rc522.PICC_HaltA();
    rc522.PCD_StopCrypto1();
}

/*---------------------------------------------------------------------------*/
void RFID_RC522::DisplayDumpReadError()
{
    dumpPiccType = MFRC522::PICC_GetType(rc522.uid.sak);

	switch (dumpPiccType)
    {
		case rc522.PICC_TYPE_ISO_14443_4:
		case rc522.PICC_TYPE_MIFARE_DESFIRE:
		case rc522.PICC_TYPE_ISO_18092:
		case rc522.PICC_TYPE_MIFARE_PLUS:
		case rc522.PICC_TYPE_TNP3XXX:
			Serial.print(F("\n\nERROR : Cannot dump and read memory contents."));
			break;
		
        case rc522.PICC_TYPE_UNKNOWN:
		case rc522.PICC_TYPE_NOT_COMPLETE:
		default:
			break; // No memory dump here
	}
}

/*--- TessBarAnn ---*/
