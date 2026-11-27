#ifndef FSR_MANAGER_H
#define FSR_MANAGER_H

#include <Arduino.h>
#include "../Constants.h"

class FsrManager
{
public:
    void begin();
    bool isAnalogSensorPin(byte pin) const;
    bool readSensor(int index) const;
    void resetSensorStates();
    bool newPressDetected(int index);

private:
    bool lastRawState[FSR_COUNT];
    bool stableState[FSR_COUNT];
    unsigned long lastRawChangeAt[FSR_COUNT];
};

#endif
