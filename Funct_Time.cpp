#include "Time.h"

bool SetTimeData(Time* time) {
	
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
	return False_Input_Value;
}