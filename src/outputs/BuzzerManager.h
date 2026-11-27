#ifndef BUZZER_MANAGER_H
#define BUZZER_MANAGER_H

#include "IGameLifecycle.h"

class BuzzerManager : public IGameLifecycle
{
public:
    void begin() override;
    void startGame() override;
    void endGame() override;
    void wrong() override;
    void successJump() override;
    void advanceLevel() override;
    void playSectionSound(unsigned int frequency);

private:
    void playNote(unsigned int frequency, unsigned int durationMs);
};

#endif
