#ifndef DISPLAY_CONTROLLER_H
#define DISPLAY_CONTROLLER_H

#include <Simple5641AS.h>

#ifndef _RTC_H
#define _RTC_H
#include "RTC.h"
#endif

const uint8_t segmentPins[] = { 4, 6, 3, 10, 9, 2, 5, 13 };
const uint8_t digitSelectionPins[] = { 12, 11, 8, 7 };

extern Simple5641AS component;


int reverseNumber(int number);
RTCTime initializeTimeDisplay();
void updateDisplay(RTCTime* currentTime);

#endif //DISPLAY_CONTROLLER_H