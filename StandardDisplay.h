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

#ifndef ___STANDARD_DISPLAY_H__
#define ___STANDARD_DISPLAY_H__

#include "Display.h"

class StandardDisplay : public Display
{
public:
    StandardDisplay(RTC *rtc);
    void loop();

private:
    void printNumber(byte number, byte position);

    uint8_t digits3x5[10][5] = {
        {7, 5, 5, 5, 7},
        {1, 1, 1, 1, 1},
        {7, 1, 7, 4, 7},
        {7, 1, 7, 1, 7},
        {5, 5, 7, 1, 1},
        {7, 4, 7, 1, 7},
        {7, 4, 7, 5, 7},
        {7, 1, 1, 1, 1},
        {7, 5, 7, 5, 7},
        {7, 5, 7, 1, 7}};

 CRGB segmentsColors[3][2] = {
        {CRGB::DarkRed, CRGB(4, 0, 0)},
        {CRGB::Yellow, CRGB(4, 4, 0)},
        {CRGB::DarkGreen, CRGB(0, 4, 0)}};
    // CRGB segmentsColors[3][2] = {
    //     {CRGB::DarkRed, CRGB(4, 0, 0)},
    //     {CRGB::DarkGreen, CRGB(0, 4, 0)},
    //     {CRGB::Yellow, CRGB(4, 4, 0)}};
};

#endif
