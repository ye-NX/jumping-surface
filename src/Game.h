#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "outputs/BuzzerManager.h"
#include "outputs/LedManager.h"
#include "outputs/LcdManager.h"
#include "inputs/FsrManager.h"

class Game
{
private:
    BuzzerManager& buzzer;
    LedManager& leds;
    LcdManager& display;
    FsrManager& fsr;

    int score;
    int level;
    int pointsInCurrentLevel;
    int pointsToNextLevel;

    int ledsPerRound;
    float speed;
    bool gameOver;

    bool target[FSR_COUNT];
    bool lastRawState[FSR_COUNT];
    bool stableState[FSR_COUNT];
    unsigned long lastRawChangeAt[FSR_COUNT];

public:
    Game(BuzzerManager& buzzerManager, LedManager& ledManager, LcdManager& LcdManager, FsrManager& fsrManager);

    void begin();
    void update();

private:
    void clearRound();
    void prepareRound();
    void playRound();
    void advanceLevelsIfNeeded();
    void finishGame();
};

#endif
