#include "LcdManager.h"

void LcdManager::begin() 
{
    lcd.begin(16, 2);
    lcd.setBacklight(1);
    lcd.clear();
}
void LcdManager::startGame() 
{
    showMessage("JUMPING GAME", "Get Ready!");
}
void LcdManager::endGame() 
{
    showMessage("GAME OVER", "Thanks for play");
}
void LcdManager::wrong() 
{
    showMessage("WRONG!", "Game Over");
}
void LcdManager::successJump() 
{
    showMessage("ROUND COMPLETE", "Well done!");
}
void LcdManager::advanceLevel() 
{
    showMessage("LEVEL UP!", "Get Ready!");
}
void LcdManager::showScore(int score, int level)
{
    lcd.setCursor(0, 0);
    lcd.print("                ");
    lcd.setCursor(0, 0);
    lcd.print("Score: ");
    lcd.print(score);
    lcd.setCursor(0, 1);
    lcd.print("                ");
    lcd.setCursor(0, 1);
    lcd.print("Level: ");
    lcd.print(level);
}
void LcdManager::showFinalScore(int score)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("GAME OVER");
    lcd.setCursor(0, 1);
    lcd.print("Score: ");
    lcd.print(score);
}
void LcdManager::showMessage(const char* line1, const char* line2)
{
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print(line1);
    lcd.setCursor(0, 1);
    lcd.print(line2);
}
