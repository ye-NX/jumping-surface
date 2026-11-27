#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <Arduino.h>
#include <Adafruit_LiquidCrystal.h>
#include "Section.h"

#define FSR_COUNT 8
#define MAX_LEDS_PER_ROUND 7

#define SPEED_MUL 1.15f
#define POINTS_MUL 1.20f

extern const unsigned long INITIAL_ROUND_TIME_MS;
extern const unsigned long FSR_DEBOUNCE_MS;
extern const int FSR_ANALOG_THRESHOLD;

extern const int PIEZO_PIN;
extern Adafruit_LiquidCrystal lcd;
extern const Section sections[FSR_COUNT];

#endif
