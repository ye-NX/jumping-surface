#include "Game.h"
Game::Game(
    BuzzerManager& buzzerManager,
    LedManager& ledManager,
    LcdManager& LcdManager,
    FsrManager& fsrManager
)
    : buzzer(buzzerManager),
      leds(ledManager),
      display(LcdManager),
      fsr(fsrManager)
{
    score = 0;
    level = 1;
    pointsInCurrentLevel = 0;
    pointsToNextLevel = 10;
    ledsPerRound = 2;
    speed = 1.0f;
    gameOver = false;
    for (int i = 0; i < FSR_COUNT; i++)
    {
        target[i] = false;
    }
}
void Game::begin()
{
    for (int i = 0; i < FSR_COUNT; i++)
    {
        pinMode(sections[i].fsrPin, INPUT);
    }
    buzzer.begin();
    leds.begin();
    display.begin();
    display.startGame();
    leds.startGame();
    buzzer.startGame();
    display.showScore(score, level);
    fsr.resetSensorStates();
}
void Game::update()
{
    if (gameOver)
        return;
    playRound();
}
// -------------------------------------------------
// ROUND MANAGEMENT
// -------------------------------------------------
void Game::clearRound()
{
    leds.allOff();
    for (int i = 0; i < FSR_COUNT; i++)
    {
        target[i] = false;
    }
}
void Game::prepareRound()
{
    clearRound();
    int order[FSR_COUNT];
    for (int i = 0; i < FSR_COUNT; i++)
    {
        order[i] = i;
    }
    // Fisher-Yates shuffle.
    for (int i = FSR_COUNT - 1; i > 0; i--)
    {
        int j = random(0, i + 1);
        int temp = order[i];
        order[i] = order[j];
        order[j] = temp;
    }
    // Turn on selected LEDs.
    for (int i = 0; i < ledsPerRound; i++)
    {
        int sectionIndex = order[i];
        target[sectionIndex] = true;
        leds.setLed(
            sections[sectionIndex].ledPin,
            true
        );
    }
    fsr.resetSensorStates();
}
void Game::playRound()
{
    prepareRound();
    display.showScore(score, level);
    const unsigned long roundDuration =
        (unsigned long)(INITIAL_ROUND_TIME_MS / speed);
    const unsigned long startTime = millis();
    int correctPresses = 0;
    while (
        (millis() - startTime) < roundDuration &&
        correctPresses < ledsPerRound
    )
    {
        for (int i = 0; i < FSR_COUNT; i++)
        {
            if (!fsr.newPressDetected(i))
                continue;
            // Play the musical note of this section.
            buzzer.playSectionSound(
                sections[i].soundFrequency
            );
            // Wrong: game over.
            if (!target[i])
            {
                delay(150);
                finishGame();
                return;
            }
            correctPresses++;
            score++;
            pointsInCurrentLevel++;
            leds.setLed(
                sections[i].ledPin,
                false
            );
            display.showScore(score, level);
        }
        delay(2);
    }
    // Not all target sensors were pressed in time.
    if (correctPresses < ledsPerRound)
    {
        finishGame();
        return;
    }
    leds.allOff();
    buzzer.successJump();
    leds.successJump();
    advanceLevelsIfNeeded();
}

void Game::advanceLevelsIfNeeded()
{
    while (pointsInCurrentLevel >= pointsToNextLevel)
    {
        pointsInCurrentLevel -= pointsToNextLevel;
        level++;
        pointsToNextLevel =
            (int)(pointsToNextLevel * POINTS_MUL + 0.5f);
        bool increasedLedCount = false;
        // Increase the number of LEDs at levels:
        // 4, 7, 10, 13, ...
        if (
            level > 1 &&
            level % 3 == 1 &&
            ledsPerRound < MAX_LEDS_PER_ROUND
        )
        {
            ledsPerRound++;
            increasedLedCount = true;
        }
        // Otherwise increase speed.
        if (!increasedLedCount)
        {
            speed *= SPEED_MUL;
        }
        buzzer.advanceLevel();
        leds.advanceLevel();
        display.advanceLevel();
        delay(700);
        display.showScore(score, level);
    }
}
void Game::finishGame()
{
    gameOver = true;
    buzzer.wrong();
    leds.wrong();
    display.wrong();
    delay(350);
    buzzer.endGame();
    leds.endGame();
    display.endGame();
    display.showFinalScore(score);
}
