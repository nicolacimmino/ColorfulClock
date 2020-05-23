//
//  Copyright (C) 2020 Nicola Cimmino
//
//    This program is free software: you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation, either version 3 of the License, or
//    (at your option) any later version.
//
//   This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __COLORFULCLOCK_DISPLAY_H__
#define __COLORFULCLOCK_DISPLAY_H__

#include <FastLED.h>
#include "RTC.h"

#define NUM_LEDS 128
#define PIN_LED_DATA 4
#define DISPLAY_BLANK CRGB::Black

class Display
{
public:
    Display(RTC *rtc);
    void setBrightness(byte brightness);
    virtual void loop() = 0;

protected:
    void clearDisplay();
    void show();
    CRGB leds[NUM_LEDS];
    RTC *rtc;    
};

#endif
