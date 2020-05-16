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

BCDDisplay::BCDDisplay(RTC *rtc) : Display(rtc)
{
}

void BCDDisplay::loop()
{
    this->clearDisplay();
    this->printNumber(this->rtc->getHours(), 0);
    this->printNumber(this->rtc->getMinutes(), 1);
    this->printNumber(this->rtc->getSeconds(), 2);
    this->printNumber(this->rtc->getDay(), 3);
    this->printNumber(this->rtc->getMonth(), 4);
    this->printNumber(this->rtc->getYear(), 5);
    
    CRGB dotsColor = CRGB::Yellow;
    dotsColor.fadeToBlackBy(200);
    this->leds[16+10] = dotsColor;
    this->leds[16+13] = dotsColor;
    this->leds[16+18] = dotsColor;
    this->leds[16+21] = dotsColor;
    this->leds[32+58] = dotsColor;
    this->leds[32+61] = dotsColor;
    
    this->show();
}

void BCDDisplay::printNumber(byte number, byte position)
{
    byte rootPosition = (position * 3);
    if (position > 2)
    {
        rootPosition = 48 + ((position - 3) * 3);
    }
    rootPosition +=16;

    byte tens = number / 10;
    for (byte ix = 0; ix < 4; ix++)
    {
        this->leds[rootPosition + (ix * 8)] = (tens & (1 << ix)) ? CRGB::Purple : CRGB::Black;
    }

    byte units = number % 10;
    for (byte ix = 0; ix < 4; ix++)
    {
        this->leds[1 + rootPosition + (ix * 8)] = (units & (1 << ix)) ? CRGB::Purple : CRGB::Black;
    }
}
