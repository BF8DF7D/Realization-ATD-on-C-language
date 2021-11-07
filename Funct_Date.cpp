#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"

bool SetDateData(Date* date){
	enum Limit_Value {
		Quantity_input_value = 3,
		Minimum_for_days_and_months = 0,
		Minimum_value_for_years = 999,
		Maximum_day = 23,
		Maximum_mounth = 59,
		Maximum_years = 9999,
		Clean_input_stream = '\n'
	};

	bool False_Input_Value = scanf("%d.%d.%d", &date->day, &date->mounth, &date->year) != Quantity_input_value
		|| (date->day <= Minimum_for_days_and_months || date->day > Maximum_day)
		|| (date->mounth <= Minimum_for_days_and_months || date->mounth > Maximum_mounth)
		|| (date->year <= Minimum_value_for_years || date->year > Maximum_years)
		|| std::cin.get() != Clean_input_stream;
	return False_Input_Value;
}