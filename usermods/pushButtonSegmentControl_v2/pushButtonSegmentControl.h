//
// Created by valentinw on 10.07.25.
//

#ifndef WLEDPUSHBUTTONCONTROLL_PUSHBUTTONSEGMENTCONTROLL_H
#define WLEDPUSHBUTTONCONTROLL_PUSHBUTTONSEGMENTCONTROLL_H

#include "wled.h"

class Usermod_PushButtonSegmentControl_v2 : public Usermod {
private:
    const int buttonPins[3] = {27, 14, 12};
    bool lastButtonState[3] = {LOW, LOW, LOW};
    bool buttonState[3] = {LOW, LOW, LOW};
    unsigned long lastDebounceTime[3] = {0, 0, 0};
    const unsigned long debounceDelay = 50;


public:
    void setup();
    void loop();
};

#endif //WLEDPUSHBUTTONCONTROLL_PUSHBUTTONSEGMENTCONTROLL_H
