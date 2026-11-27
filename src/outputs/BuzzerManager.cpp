#include "BuzzerManager.h"

void BuzzerManager::begin() 
{
    pinMode(PIEZO_PIN, OUTPUT);
    noTone(PIEZO_PIN);
    digitalWrite(PIEZO_PIN, LOW);
}

void BuzzerManager::startGame() 
{
    playNote(523, 140);
    playNote(659, 140);
        playNote(784, 240);
}

void BuzzerManager::endGame() 
{
    playNote(392, 220);
    playNote(330, 220);
        playNote(262, 450);
}

void BuzzerManager::wrong() 
{
    playNote(180, 350);
}

void BuzzerManager::successJump() 
{
    playNote(784, 100);
}

void BuzzerManager::advanceLevel() 
{
    playNote(523, 100);
    playNote(659, 100);
    playNote(784, 220);
}

void BuzzerManager::playSectionSound(unsigned int frequency)
{
        tone(PIEZO_PIN, frequency, 140);
}

void BuzzerManager::playNote(unsigned int frequency, unsigned int durationMs)
    {
        tone(PIEZO_PIN, frequency, durationMs);
        delay(durationMs + 25);
        noTone(PIEZO_PIN);
        digitalWrite(PIEZO_PIN, LOW);
    }
