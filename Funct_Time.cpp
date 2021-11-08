#define _CRT_SECURE_NO_WARNINGS
#include "Time.h"

void SetTimeData(Time* time) {
	bool False_Input_Value;
	do {
		std::cout << " Время приёма: ";
		False_Input_Value = BoolInputTime(time);
		if (False_Input_Value) {
			std::cout << "\n <Время приёма введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool BoolInputTime(Time* time) {
	
	enum Limit_Value {
		Quantity_input_value = 2,
		Minimum_value_for_all = 0,
		Maximum_hour = 23,
		Maximum_minutes = 59,
		Clean_input_stream = '\n'
	};
	
	bool False_Input_Value = scanf("%d.%d", &time->hour, &time->minutes) != Quantity_input_value
		|| (time->hour < Minimum_value_for_all || time->hour > Maximum_hour)
		|| (time->minutes < Minimum_value_for_all || time->minutes > Maximum_minutes)
		|| std::cin.get() != Clean_input_stream;
	std::cin.clear();

	return False_Input_Value;
}