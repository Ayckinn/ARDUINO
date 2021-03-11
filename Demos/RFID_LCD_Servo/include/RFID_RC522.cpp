#include "../header/RFID_RC522.hpp"
#include "../header/ServoSG90.hpp"
#include "../header/LCD16x2.hpp"

RC522_RFID::RC522_RFID() {}
ServoSG90 sg90Motor;
LCD16x2 lcd_screen;


void RC522_RFID::Ignition()
{
    //-- Bus SPI init
    SPI.begin();
    //-- RFID RC522 Module init
    rc522.PCD_Init();
    //-- Display firmware version of RC522
    rc522.PCD_DumpVersionToSerial();
}

/*---------------------------------------------------------------------------*/
//-- Put the RFID on standby mode, waiting for card or tag
void RC522_RFID::WaitScanUID()
{
    //-- When the module wait an UID, the door is closed
    sg90Motor.CloseDoor();
    Serial.println("RFID module is ready...");
    //-- Reset loop if no new card detected
    if(!rc522.PICC_IsNewCardPresent()) { return; }
}

/*---------------------------------------------------------------------------*/
void RC522_RFID::ReadUID()
{   
    //-- Verify if the UID has been readed well, else, reset loop
    if(!rc522.PICC_ReadCardSerial()) { return; }

    //-- Get UID card or UID tag number : 
    //-- 1st group [0], 2nd group [1], 3rd group [2], 4th group [3], DEC = INT
    UID_Card_Scanned = String(rc522.uid.uidByte[0], DEC) + " " + 
               String(rc522.uid.uidByte[1], DEC) + " " +
               String(rc522.uid.uidByte[2], DEC) + " " +
               String(rc522.uid.uidByte[3], DEC);

    //-- Stop reading card
    rc522.PICC_HaltA();
    //-- Stop encryption of mudule
    rc522.PCD_StopCrypto1();

    Serial.print("UID tag : ");
    Serial.println(UID_Card_Scanned);

    if(UID_Card_Scanned == UID_AYCKINN_CARD)
    {
        sg90Motor.OpenDoor();
        lcd_screen.AccessOK("AYCKINN");
    }
    else if(UID_Card_Scanned == UID_MOORLAH_TAG)
    {
        sg90Motor.OpenDoor();
        lcd_screen.AccessOK("MOORLAH");
    }
    else
    {
        sg90Motor.CloseDoor();
        lcd_screen.AccessDenied(); 
    }
}
/*--- TessBarAnn ---*/