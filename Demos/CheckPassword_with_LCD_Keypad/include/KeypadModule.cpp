#include "../header/KeypadModule.hpp"
#include "../header/LCDScreen.hpp"
#include "../header/Leds.hpp"

LEDS leds;
LCD_Screen lcdScreen;

Keypad_Module::Keypad_Module() {}


/*===========================================================================*/
void Keypad_Module::Check_Password()
{
    StartDisplay();
    
    //-- Get and returns single value key ([char]) when pressed
    getKeyTouch = padModule.getKey();

    UserChoice();
    PasswordControl();
}

/*===========================================================================*/
void Keypad_Module::StartDisplay()
{
    //-- Reset [empy_pass] container with [memset(pointer, int value, size_t count)]
    //     pointer : Specify the memory bloc valeu to reset
    //     value   : The value to use fot the memory bloc (0 = empty)
    //     size    : Indicate the number of octets to reset
    memset(empty_pass, 0, sizeof(empty_pass));
    //-- Set the first at the beginning of the list
    char_index = 0;
    //-- Set the LCD cursor at the position 9 at start
    cursorPos = 9;

    //-- Trun off leds
    leds.Green_LED(LOW);
    leds.Red_LED(LOW);

      lcd.clear();    
    lcd.setCursor(0, 0);
    lcd.print("Passwd :");
    //-- Start cursor position at 9
    lcd.setCursor(cursorPos, 0);
    //-- Logo on second line
    lcd.setCursor(0, 1);
    lcd.print("Ayckinn Robotics");
}

/*===========================================================================*/
void Keypad_Module::UserChoice()
{
    while(getKeyTouch != '#')
    {
        //-- Wait key
        getKeyTouch = padModule.getKey();

        if(getKeyTouch != NO_KEY && getKeyTouch != '#')
        {
            lcd.setCursor(cursorPos, 0);
            //-- Hide key by '.' symbol
            lcd.print(".");
            //-- Set cursor to the next LCD position
            cursorPos++;
            //-- Add key in list
            empty_pass[char_index] = getKeyTouch;
            //-- Go to th enext index for a new key
            char_index++;
        }
    }
}

/*===========================================================================*/
void Keypad_Module::PasswordControl()
{
    //-- Ayckinn password
    //-- [strcmp] allows to compare the passwords, if equal, value returns 0
    if(strcmp(empty_pass, "*8436B0") == 0)
    {
        Serial.println("AYCKINN PASS OK");
        lcdScreen.Pass_OK("Ayckinn");
    }
    //-- Moorlah Password
    else if(strcmp(empty_pass, "1980*CA") == 0)
    {
        Serial.println("MOORLAH PASS OK");
        lcdScreen.Pass_OK("Moorlah");
    }
    else
    {
        lcdScreen.Pass_NOK();
        Serial.println("PASS NOK");
    }
}

/*--- TessBarAnn ---*/