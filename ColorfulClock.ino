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

#include "Display.h"
#include "RomanDisplay.h"
#include "BCDDisplay.h"
#include "StandardDisplay.h"
#include "RTC.h"
#include "ToFSensor.h"

#define NUM_DISPLAYS 3

Display *display;
RTC *rtc;
ToFSensor *tofSensor;

byte activeDisplayIndex = 0;
bool displayDimmed = false;

void setup()
{
    Serial.begin(115200);
    rtc = new RTC();

    rtc->initialize();

    display = new BCDDisplay(rtc);
    tofSensor = new ToFSensor(onAction);
}

void changeClock()
{
    activeDisplayIndex = (activeDisplayIndex + 1) % NUM_DISPLAYS;
    delete display;
    switch (activeDisplayIndex)
    {
    case 0:
        display = new BCDDisplay(rtc);
        break;
    case 1:
        display = new RomanDisplay(rtc);
        break;
    case 2:
        display = new StandardDisplay(rtc);
        break;
    }
}

void toggleDim()
{
    displayDimmed = !displayDimmed;
}

void onAction(uint8_t action)
{
    switch (action)
    {
    case 1:
        changeClock();
        break;
    case 2:
        toggleDim();
        break;
    }
}

void loop()
{
    display->setBrightness(displayDimmed ? 50 : 100);
    display->loop();
    tofSensor->loop();
}
