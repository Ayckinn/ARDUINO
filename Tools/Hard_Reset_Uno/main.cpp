#include <Arduino.h>

#define RESET_PIN 2

void setup()
{
    Serial.begin(9600);

    pinMode(RESET_PIN, OUTPUT);
}

void loop()
{
    Serial.println("Hard reset in progress...");
    digitalWrite(RESET_PIN, HIGH);
    delay(5000);

    digitalWrite(RESET_PIN, LOW);
    Serial.println("Arduino Uno has been rested successfully !");
}