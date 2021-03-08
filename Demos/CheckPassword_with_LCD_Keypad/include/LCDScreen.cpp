#include "../header/LCDScreen.hpp"
#include "../header/Leds.hpp"

LEDS ledz;


void LCD_Screen::Logo()
{
    lcd.setCursor(5, 0);
    lcd.print("Ayckinn");
    lcd.setCursor(4, 1);
    lcd.print("Robotics");
    delay(4000);
    lcd.clear();
}

void LCD_Screen::Pass_OK(String username)
{
    ledz.Green_LED(HIGH);
    ledz.Red_LED(LOW);

    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("Password OK");
    lcd.setCursor(2, 1);
    lcd.print("Hi, " + username);
    delay(3000);
}

void LCD_Screen::Pass_NOK()
{
    ledz.Green_LED(LOW);
    ledz.Red_LED(HIGH);
    
    lcd.clear();
    lcd.setCursor(4, 0);
    lcd.print("Unknown");
    lcd.setCursor(4, 1);
    lcd.print("Password");
    delay(3000);
}

/*--- TessBarAnn ---*/