#pragma once
#include <iostream>

struct Date {
	int day,
		mounth,
		year;
};

bool BoolInputData(Date*);
void SetDateData(Date*);