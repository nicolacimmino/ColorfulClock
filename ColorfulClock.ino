//
//  A colorful clock based on an 8x8 addressable LEDs panel.
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
#include "RTC.h"

RomanDisplay display;
RTC rtc;

void setup()
{
    display.clearDisplay();
    display.show();

    rtc.initialize();
}

void loop()
{
    display.clearDisplay();
    display.printNumber(rtc.getHours(), 0, 8);
    display.printNumber(rtc.getMinutes(), 8 * 1, 8);
    display.printNumber(rtc.getSeconds(), 8 * 2, 8);
    display.printNumber(rtc.getDay(), 8 * 3, 8);
    display.printNumber(rtc.getMonth(), 8 * 4, 8);
    display.printNumber(rtc.getYear(), 8 * 5, 8);
    display.printPositional(rtc.getDayOfWeek() - 1, 8 * 6);
    display.printNumber(rtc.getTemperature(), 8 * 7, 8);
    
    display.show();

    delay(1000);
}
