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

#include "StandardDisplay.h"

StandardDisplay::StandardDisplay(RTC *rtc) : Display(rtc)
{
}

void StandardDisplay::loop()
{
    this->clearDisplay();
    this->printNumber(this->rtc->getHours() / 10, 0);
    this->printNumber(this->rtc->getHours() % 10, 1);
    this->printNumber(this->rtc->getMinutes() / 10, 2);
    this->printNumber(this->rtc->getMinutes() % 10, 3);
    this->printNumber(this->rtc->getSeconds() / 10, 4);
    this->printNumber(this->rtc->getSeconds() % 10, 5);

    // CRGB dotsColor = CRGB::Yellow;
    // dotsColor.fadeToBlackBy(200);
    // this->leds[16 + 10] = dotsColor;
    // this->leds[16 + 13] = dotsColor;
    // this->leds[16 + 18] = dotsColor;
    // this->leds[16 + 21] = dotsColor;
    // this->leds[32 + 58] = dotsColor;
    // this->leds[32 + 61] = dotsColor;

    this->show();
}

void StandardDisplay::printNumber(byte number, byte position)
{
    byte rootPosition = ((position % 2) * 4);
    rootPosition += (position / 2) * 40;

    for (byte row = 0; row < 5; row++)
    {
        uint8_t pixels = this->digits3x5[8][row];

        for (byte col = 0; col < 3; col++)
        {
            if ((pixels & (1 << (2 - col))))
            {
                this->leds[rootPosition + col + (row * 8)] = this->segmentsColors[position / 2][1];
            }
        }
    }

    for (byte row = 0; row < 5; row++)
    {
        uint8_t pixels = this->digits3x5[number][row];

        for (byte col = 0; col < 3; col++)
        {
            if ((pixels & (1 << (2 - col))))
            {
                this->leds[rootPosition + col + (row * 8)] = this->segmentsColors[position / 2][0];
            }
        }
    }
}
