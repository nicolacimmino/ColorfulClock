//
//  RTC wraps the logic to drive a DS3234 RTC Chip.
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

#ifndef __RTC_H__
#define __RTC_H__

#include <Arduino.h>
#include "Wire.h"
#include "uRTCLib.h"
class RTC
{
public:
  void initialize();
  void setTime(int v_hour, int v_minute, int v_second);
  byte getHours();
  byte getMinutes();
  byte getSeconds();
  byte getMonth();
  byte getDay();
  byte getYear();
  byte getDayOfWeek();
  byte getTemperature();
private:
  uRTCLib rtc = uRTCLib(0x68);
};

#endif