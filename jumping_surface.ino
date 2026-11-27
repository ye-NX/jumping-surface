#include <Arduino.h>
#include <Adafruit_LiquidCrystal.h>
#include <EEPROM.h>
#include "src/Game.h"
#include "src/outputs/BuzzerManager.h"
#include "src/outputs/LedManager.h"
#include "src/outputs/LcdManager.h"
#include "src/inputs/FsrManager.h"

BuzzerManager buzzerManager;
LedManager ledManager;
LcdManager LcdManager;
FsrManager fsrManager;

Game game(
    buzzerManager,
    ledManager,
    LcdManager,
    fsrManager
);

void setup()
{
    game.begin();
}

void loop()
{
    game.update();
}