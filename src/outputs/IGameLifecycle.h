#ifndef INTERFACE_H
#define INTERFACE_H

#include <Arduino.h>
#include "../Constants.h"

class IGameLifecycle
{
public:
    virtual void begin() = 0;
    virtual void startGame() = 0;
    virtual void endGame() = 0;
    virtual void wrong() = 0;
    virtual void successJump() = 0;
    virtual void advanceLevel() = 0;

    virtual ~IGameLifecycle() = default;
};

#endif
