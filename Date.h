#pragma once
#include <iostream>

struct Date {
	int day,
		mounth,
		year;
};

bool BoolFormatInputDate(Date*);
void SetDateData(Date*);
void PrintDateInfo(Date);