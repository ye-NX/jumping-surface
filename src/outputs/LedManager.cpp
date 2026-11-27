#include "LedManager.h"
void LedManager::begin() 
{
    for (int i = 0; i < FSR_COUNT; i++)
    {
        pinMode(sections[i].ledPin, OUTPUT);
    }
    allOff();
}
void LedManager::allOff()
{
    for (int i = 0; i < FSR_COUNT; i++)
    {
        digitalWrite(sections[i].ledPin, LOW);
    }
}
void LedManager::setLed(int ledPin, bool turnOn)
{
    digitalWrite(ledPin, turnOn ? HIGH : LOW);
}
void LedManager::startGame() 
{
    allOn();
    delay(450);
    allOff();
}
void LedManager::endGame() 
{
    allOff();
}
void LedManager::wrong() 
{
    for (int repeat = 0; repeat < 3; repeat++)
    {
        allOn();
        delay(180);
        allOff();
        delay(180);
    }
}
void LedManager::successJump() 
{
    allOn();
    delay(100);
    allOff();
}
void LedManager::advanceLevel() 
{
    for (int repeat = 0; repeat < 2; repeat++)
    {
        allOn();
        delay(140);
        allOff();
        delay(140);
    }
}
void LedManager::allOn()
{
    for (int i = 0; i < FSR_COUNT; i++)
    {
        digitalWrite(sections[i].ledPin, HIGH);
    }
}
