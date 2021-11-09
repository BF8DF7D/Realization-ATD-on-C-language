#pragma once
#include <iostream>

struct Time {
	 int hour,
		minutes;
};

bool BoolFormatInputTime(Time*);
void SetTimeData(Time*);
void PrintTimeInfo(Time);