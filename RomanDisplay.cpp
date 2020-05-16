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

#include "RomanDisplay.h"

RomanDisplay::RomanDisplay(RTC *rtc) : Display(rtc)
{

}

void RomanDisplay::loop()
{
    this->clearDisplay();
    this->printNumber(this->rtc->getHours(), 8 * 2 , 8);
    this->printNumber(this->rtc->getMinutes(), 8 * 3, 8);
    this->printNumber(this->rtc->getSeconds(), 8 * 4, 8);
    this->printNumber(this->rtc->getDay(), 8 * 7, 8);
    this->printNumber(this->rtc->getMonth(), 8 * 8, 8);
    this->printNumber(2000 + this->rtc->getYear(), 8 * 9, 8);
    this->printPositional(this->rtc->getDayOfWeek() - 1, 8 * 10);
    this->printNumber(this->rtc->getTemperature(), 8 * 13, 8);

    this->show();
}

void RomanDisplay::convertToRoman(unsigned int number, char *result)
{
    struct
    {
        unsigned int value;
        const char *symbols;
    } romanDigits[] = {
        {1000, "M"},
        {50, "L"},
        {40, "XL"},
        {10, "X"},
        {9, "IX"},
        {5, "V"},
        {4, "IV"},
        {1, "I"}};

    strcpy(result, "");
    while (number)
    {
        for (int ix = 0; ix < sizeof(romanDigits) / sizeof(*romanDigits); ix++)
        {
            if (number >= romanDigits[ix].value)
            {
                number -= romanDigits[ix].value;
                strcat(result, romanDigits[ix].symbols);
                break;
            }
        }
    }
}

void RomanDisplay::printNumber(unsigned int number, byte startIndex, byte sectionLength)
{
    char romanNumeralBuffer[10];
    convertToRoman(number, romanNumeralBuffer);

    //startIndex += ((sectionLength - 2 * strlen(romanNumeralBuffer)) >> 1);

    CRGB colour = CRGB::White;

    for (char *bufferIterator = romanNumeralBuffer; *bufferIterator; ++bufferIterator)
    {
        {
            switch (*bufferIterator)
            {
            case 'I':
                colour = ROMAN_DISPLAY_I;
                break;
            case 'V':
                colour = ROMAN_DISPLAY_V;
                break;
            case 'X':
                colour = ROMAN_DISPLAY_X;
                break;
            case 'L':
                colour = ROMAN_DISPLAY_L;
                break;
            case 'M':
                colour = ROMAN_DISPLAY_M;
                break;                
            }

            // Due to mechanical limiations in the proto it was more handy to
            // have leds indexed counterclockwise, however, it's far more logical
            // to read the clock clocwise. We fix it here because software is
            // cheaper than disassembling and rewiring.
            this->leds[startIndex] = colour;
            startIndex += 1;
        }
    }
}

void RomanDisplay::printPositional(byte number, byte startIndex)
{
    this->leds[startIndex + number] = CRGB::Violet;
}