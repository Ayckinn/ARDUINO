#ifndef KEYPADMODULE_HPP
#define KEYPADMODULE_HPP

#include <Arduino.h>
#include <Keypad.h>  //-- By Mark Stanley


class Keypad_Module
{
    public:
        Keypad_Module();

        void Check_Password();
        void StartDisplay();
        void UserChoice();
        void PasswordControl();


    private:
        /*========================== KEYMAP SECTION =========================*/
        //-- 4 rows on keypad
        static const byte ROWS = 4;
        //-- 4 columns on keypad
        static const byte COLS = 4;
        //-- Arduino pinouts
        byte row_pins[ROWS] = {9, 8, 7, 6};
        byte col_pins[COLS] = {5, 4, 3, 2};
        //-- Define buttons symbols on keypad
        char keypad_buttons[ROWS][COLS] = 
        {
            {'1', '2', '3', 'A'},
            {'4', '5', '6', 'B'},
            {'7', '8', '9', 'C'},
            {'*', '0', '#', 'D'}
        };
        //-- Keypad init
        Keypad padModule = Keypad(makeKeymap(keypad_buttons), row_pins, col_pins, ROWS, COLS);
        //-- Get key value when pressed
        char getKeyTouch;

        /*========================= PASSWORD SECTION ========================*/
        //-- Empty pass container (7 characters)
        char empty_pass[8] = " ";
        //-- Index of character in list (start at 0 = '*')
        int char_index = 0;
        //-- LCD Cursor position to display letters one after one
        int cursorPos;
};

#endif  //-- KEYPADMODULE_HPP