#include "Constants.h"

const unsigned long INITIAL_ROUND_TIME_MS = 10000UL;
const unsigned long FSR_DEBOUNCE_MS = 25UL;

const int FSR_ANALOG_THRESHOLD = 300;

// Piezo moved to D1.
// Disconnect it while uploading if necessary.
const int PIEZO_PIN = 1;

// Tinkercad: MCP23008-based, address 32 (0x20).
Adafruit_LiquidCrystal lcd(0);

const Section sections[FSR_COUNT] =
{
    {1, 9, 13, 262},  // Do
    {2, 8, 12, 294},  // Re
    {3, 7, 11, 330},  // Mi
    {4, 6, 10, 349},  // Fa
    {5, 5, A0, 392},  // Sol
    {6, 4, A1, 440},  // La
    {7, 3, A3, 494},  // Si
    {8, 2, A2, 523}   // Do
};
