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
#include "BCDDisplay.h"
#include "RTC.h"

#define NUM_DISPLAYS 2
#define BUTTON_PIN 8

Display *display;
RTC rtc;
byte activeDisplayIndex = 0;

void setup()
{
    rtc.initialize();

    display = new BCDDisplay(&rtc);

    pinMode(BUTTON_PIN, INPUT_PULLUP);
}

void loop()
{
    display->loop();

    if (digitalRead(BUTTON_PIN) == LOW)
    {
        activeDisplayIndex = (activeDisplayIndex + 1) % NUM_DISPLAYS;
        delete display;
        switch (activeDisplayIndex)
        {
        case 0:
            display = new BCDDisplay(&rtc);
            break;
        case 1:
            display = new RomanDisplay(&rtc);
            break;
        }
        while (digitalRead(BUTTON_PIN) == LOW)
        {
            delay(1);
        }        
    }
}
