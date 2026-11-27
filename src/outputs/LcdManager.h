#ifndef LCD_MANAGER_H
#define LCD_MANAGER_H

#include "IGameLifecycle.h"

class LcdManager : public IGameLifecycle
{
public:
    void begin() override;
    void startGame() override;
    void endGame() override;
    void wrong() override;
    void successJump() override;
    void advanceLevel() override;
    void showScore(int score, int level);
    void showFinalScore(int score);

private:
    void showMessage(const char* line1, const char* line2);
};

#endif
