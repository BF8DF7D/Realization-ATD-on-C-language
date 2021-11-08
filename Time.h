#pragma once
#include <iostream>

struct Time {
	 int hour,
		minutes;
};

bool BoolInputTime(Time*);
void SetTimeData(Time*);