//
//  RomanDisplay wraps the logic to drive a string of WS2812B addressable LEDs and show
//  color coded roman numerals.
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

#ifndef __ROMAN_DISPLAY_H__
#define __ROMAN_DISPLAY_H__

#include <FastLED.h>
#include "RTC.h"

#define NUM_LEDS 64
#define PIN_LED_DATA 5
#define ROMAN_DISPLAY_BLANK CRGB(0, 0, 0)
#define ROMAN_DISPLAY_I CRGB::Blue;
#define ROMAN_DISPLAY_V CRGB::Green;
#define ROMAN_DISPLAY_X CRGB::Red;
#define ROMAN_DISPLAY_L CRGB::Yellow;

class RomanDisplay
{
public:
    RomanDisplay(RTC *rtc);
    void setBrightness(byte brightness);
    void loop();

private:
    CRGB leds[NUM_LEDS];
    RTC *rtc;
    void convertToRoman(byte number, char *result);
    void printNumber(byte number, byte startIndex, byte sectionLength);
    void printPositional(byte number, byte startIndex);
    void clearDisplay();
    void show();
};

#endif
