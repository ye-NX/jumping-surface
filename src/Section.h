#ifndef SECTION_H
#define SECTION_H

#include <Arduino.h>

struct Section
{
    const byte sectionId;
    const byte ledPin;
    const byte fsrPin;
    const unsigned int soundFrequency;
};

#endif
