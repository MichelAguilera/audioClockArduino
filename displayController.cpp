#include "displaycontroller.h"


Simple5641AS component(segmentPins, digitSelectionPins);


int reverseNumber(int number) {
    int reversed = 0;

    while (number > 0) {
        int digit = number % 10;       
        reversed = reversed * 10 + digit;
        number = number / 10;         
    }

    return reversed;
}

RTCTime initializeTimeDisplay() {
    RTC.begin();

    RTCTime startTime(4, Month::NOVEMBER, 2024, 13, 10, 0, DayOfWeek::WEDNESDAY, SaveLight::SAVING_TIME_ACTIVE);
    RTC.setTime(startTime);

    return startTime;
}

void updateDisplay(RTCTime* currentTime) {
    int timeToDisplay = (currentTime->getHour() * 100) + currentTime->getMinutes();

    component.displayNumber(1, reverseNumber(timeToDisplay), 2);
}