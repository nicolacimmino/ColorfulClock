//
//  RTC wraps the logic to drive a DS3234 RTC Chip.
//
//  Copyright (C) 2019 Nicola Cimmino
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

#include "RTC.h"

#define DS3234_CS_PIN 10
#define DS3234_VCC_PIN A1
#define DS3234_GND_PIN A2

////////////////////////////////////////////////////////////////////////////////
//
void RTC::initialize()
{
    Wire.begin();
}

void RTC::setTime(int v_hour, int v_minute, int v_second)
{
    //this->rtc.set(this->getSeconds(), this->getMinutes(), this->getHours(), 3, 13, 5, 20);
}

byte RTC::getHours()
{
    this->rtc.refresh();
    return this->rtc.hour();
}

byte RTC::getMinutes()
{
    this->rtc.refresh();
    return this->rtc.minute();
}

byte RTC::getSeconds()
{
    this->rtc.refresh();
    return this->rtc.second();
}

byte RTC::getDay()
{
    this->rtc.refresh();
    return this->rtc.day();
}

byte RTC::getDayOfWeek()
{
    this->rtc.refresh();
    return this->rtc.dayOfWeek();
}

byte RTC::getMonth()
{
    this->rtc.refresh();
    return this->rtc.month();
}

byte RTC::getYear()
{
    this->rtc.refresh();
    return this->rtc.year();
}

byte RTC::getTemperature()
{
    this->rtc.refresh();
    return this->rtc.temp() / 100;
}
