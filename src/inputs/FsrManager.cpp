#include "FsrManager.h"

void FsrManager::begin()
{
    resetSensorStates();
}

bool FsrManager::isAnalogSensorPin(byte pin) const
{
    return pin == A0 ||
           pin == A1 ||
           pin == A2 ||
           pin == A3;
}

bool FsrManager::readSensor(int index) const
{
    const byte pin = sections[index].fsrPin;

    if (isAnalogSensorPin(pin))
    {
        return analogRead(pin) >= FSR_ANALOG_THRESHOLD;
    }

    return digitalRead(pin) == HIGH;
}

void FsrManager::resetSensorStates()
{
    unsigned long now = millis();

    for (int i = 0; i < FSR_COUNT; i++)
    {
        bool current = readSensor(i);

        lastRawState[i] = current;
        stableState[i] = current;
        lastRawChangeAt[i] = now;
    }
}

bool FsrManager::newPressDetected(int index)
{
    bool rawState = readSensor(index);
    unsigned long now = millis();

    if (rawState != lastRawState[index])
    {
        lastRawState[index] = rawState;
        lastRawChangeAt[index] = now;
    }

    if ((now - lastRawChangeAt[index]) >= FSR_DEBOUNCE_MS &&
        stableState[index] != lastRawState[index])
    {
        stableState[index] = lastRawState[index];
        return stableState[index];
    }

    return false;
}
