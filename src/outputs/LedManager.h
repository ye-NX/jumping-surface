#ifndef LED_MANAGER_H
#define LED_MANAGER_H

#include "IGameLifecycle.h"

class LedManager : public IGameLifecycle
{
public:
    void begin() override;
    void allOff();
    void setLed(int ledPin, bool turnOn);
    void startGame() override;
    void endGame() override;
    void wrong() override;
    void successJump() override;
    void advanceLevel() override;

private:
    void allOn();
};

#endif
