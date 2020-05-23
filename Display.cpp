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

#include "Display.h"

Display::Display(RTC *rtc)
{
    this->rtc = rtc;
    FastLED.addLeds<WS2812, PIN_LED_DATA, GRB>(this->leds, NUM_LEDS);
    FastLED.setBrightness(127);
}

void Display::setBrightness(byte brightness)
{
    FastLED.setBrightness(brightness);
}


void Display::clearDisplay()
{
    for (int ix = 0; ix < NUM_LEDS; ix++)
    {
        this->leds[ix] = DISPLAY_BLANK;
    }

    if(this->activityIndicator) {
        this->leds[NUM_LEDS - 1] = CRGB::Red;
    }
}

void Display::show()
{
    FastLED.show();
}
