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

#include "BCDDisplay.h"

BCDDisplay::BCDDisplay(RTC *rtc)
{
    this->rtc = rtc;
    FastLED.addLeds<WS2812B, PIN_LED_DATA, GRB>(this->leds, NUM_LEDS);
    FastLED.setBrightness(10);
}

void BCDDisplay::setBrightness(byte brightness)
{
    FastLED.setBrightness(brightness);
}

void BCDDisplay::loop()
{
    this->clearDisplay();
    this->printNumber(this->rtc->getHours(), 0);
    this->printNumber(this->rtc->getMinutes(), 1);
    this->printNumber(this->rtc->getSeconds(), 2);
    //this->printNumber(this->rtc->getDay(), 3);
    // this->printNumber(this->rtc->getMonth(), 8 * 4, 8);
    // this->printNumber(this->rtc->getYear(), 8 * 5, 8);
    // this->printPositional(this->rtc->getDayOfWeek() - 1, 8 * 6);
    // this->printNumber(this->rtc->getTemperature(), 8 * 7, 8);

    this->show();
}

void BCDDisplay::clearDisplay()
{
    for (int ix = 0; ix < NUM_LEDS; ix++)
    {
        this->leds[ix] = ROMAN_DISPLAY_BLANK;
    }

    CRGB dotsColor = CRGB::Yellow;
    dotsColor.fadeToBlackBy(200);
    this->leds[10] = dotsColor;
    this->leds[13] = dotsColor;
    this->leds[18] = dotsColor;
    this->leds[21] = dotsColor;
}

void BCDDisplay::show()
{
    FastLED.show();
}

void BCDDisplay::printNumber(byte number, byte position)
{
    byte tens = number / 10;
    for (byte ix = 0; ix < 4; ix++)
    {
        this->leds[(position * 3) + (ix * 8)] = (tens & (1 << ix)) ? CRGB::Purple : CRGB::Black;
    }

    byte units = number % 10;
    for (byte ix = 0; ix < 4; ix++)
    {
        this->leds[1 + (position * 3) + (ix * 8)] = (units & (1 << ix)) ? CRGB::Purple : CRGB::Black;
    }
}
