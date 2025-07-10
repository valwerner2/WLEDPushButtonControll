//
// Created by valentinw on 10.07.25.
//

#include "pushButtonSegmentControl.h"


void Usermod_PushButtonSegmentControl_v2::setup() {
    if (!Serial) {
        Serial.begin(115200);  // or whatever baud rate you're using
        delay(100);
    }
    Serial.print("SETTING UP MOD\n");
    for (int i = 0; i < 3; i++) {
        Serial.print("SETTING BUTTON ");
        Serial.print(i);
        Serial.print(" \n");
        pinMode(buttonPins[i], INPUT_PULLDOWN); // HIGH ACTIVE
    }
}

void Usermod_PushButtonSegmentControl_v2::loop() {
    for (int i = 0; i < 3; i++) {
        bool reading = digitalRead(buttonPins[i]);

        //butten changed state, remember when
        if (reading != lastButtonState[i]) {
            lastDebounceTime[i] = millis();
        }

        //no more bounce
        if ((millis() - lastDebounceTime[i]) > debounceDelay) {
            //button pressed
            if (reading != buttonState[i]) {
                buttonState[i] = reading;
                // button pressed HIGH and does segment exists?
                if (buttonState[i] == HIGH && i < strip.getSegmentsNum()) {
                    // Toggle segment power
                    Segment& seg = strip.getSegment(i);
                    bool currentOnState = seg.getOption(SEG_OPTION_ON);
                    seg.setOption(SEG_OPTION_ON, !currentOnState); // Toggle Segment

                    // Update LEDs
                    strip.show();
                }
            }
        }
        lastButtonState[i] = reading;
    }
}


static Usermod_PushButtonSegmentControl_v2 example_usermod;
REGISTER_USERMOD(example_usermod);