#include "../header/LCD16x2.hpp"
#include "../header/LEDLight.hpp"

LEDLight ledz;


void LCD16x2::DisplayLogo()
{
    Serial.println("LOGO OK...");
    lcd.setCursor(0, 0);
    lcd.print("Ayckinn Robotics");
    lcd.setCursor(0, 1);
    lcd.print("RFID RC522 Test");
    delay(4000);
    lcd.clear();
}

/*---------------------------------------------------------------------------*/
void LCD16x2::DisplayWaitUID()
{
    Serial.println("Waiting for scan...");

    ledz.Green_LED(LOW);
    ledz.Red_LED(LOW);

    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("SCAN YOUR");
    lcd.setCursor(4, 1);
    lcd.print("CARD HERE");
}

/*---------------------------------------------------------------------------*/
void LCD16x2::AccessOK(String name)
{
    ledz.Green_LED(HIGH);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("UID : ");
    lcd.setCursor(7, 0);
    lcd.print(name);
    lcd.setCursor(1, 1);
    lcd.print("ACCESS GRANTED");
    delay(3000);
    DisplayWaitUID();
}

/*---------------------------------------------------------------------------*/
void LCD16x2::AccessDenied()
{
    ledz.Red_LED(HIGH);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("UNKNOWN UID");
    lcd.setCursor(2, 1);
    lcd.print("ACCESS DENIED");
    delay(3000);
    DisplayWaitUID();
}

/*--- TessBarAnn ---*/