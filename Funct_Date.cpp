#define _CRT_SECURE_NO_WARNINGS
#include "Date.h"
#include <iomanip>

void SetDateData(Date* date) {
	bool False_Input_Value;
	do {
		std::cout << " Дата: ";
		False_Input_Value = BoolFormatInputDate(date);
		if (False_Input_Value) {
			std::cout << "\n <Дата введена некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool BoolFormatInputDate(Date* date){
	enum Limit_Value {
		Quantity_input_value = 3,
		Minimum_for_days_and_months = 0,
		Minimum_value_for_years = 999,
		Maximum_day = 31,
		Maximum_mounth = 12,
		Maximum_years = 9999,
		Clean_input_stream = '\n'
	};

	bool False_Input_Value = scanf("%d.%d.%d", &date->day, &date->mounth, &date->year) != Quantity_input_value
		|| (date->day <= Minimum_for_days_and_months || date->day > Maximum_day)
		|| (date->mounth <= Minimum_for_days_and_months || date->mounth > Maximum_mounth)
		|| (date->year <= Minimum_value_for_years || date->year > Maximum_years)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

void PrintDateInfo(Date date) {
	std::cout << std::setfill('0') << std::setw(2) << date.day << ".";
	std::cout << std::setfill('0') << std::setw(2) << date.mounth << ".";
	std::cout << std::setw(4) << date.year;
	std::cout.fill(' ');
}