#define _CRT_SECURE_NO_WARNINGS
#include "Pasport.h"
#include <iomanip>

void SetPasportData(Pasport* pasport){
	bool False_Input_Value;
	do {
		std::cout << " Паспорт: ";
		False_Input_Value = BoolFormatInputPasport(pasport);
		if (False_Input_Value) {
			std::cout << "\n <Паспортные данные введены некорректно>" << std::endl;
		}
	} while (False_Input_Value);
}

bool BoolFormatInputPasport(Pasport* pasport) {
	enum Limit_Value {
		Quantity_inpyt_value = 2,
		Minimum_value_for_all = 0,
		Maximum_for_series = 9999,
		Maximum_for_number = 999999,
		Clean_input_stream = '\n'
	};
		bool False_Input_Value = scanf("%d %d", &pasport->Series, &pasport->Number) != Quantity_inpyt_value
		|| (pasport->Series <= Minimum_value_for_all || pasport->Series > Maximum_for_series)
		|| (pasport->Number < Minimum_value_for_all || pasport->Number > Maximum_for_number)
		|| std::cin.get() != Clean_input_stream;
	
	if (False_Input_Value)
		while (std::cin.get() != '\n');

	return False_Input_Value;
}

void PrintPasportInfo(Pasport pasport) {
	std::cout << std::setfill('0') << std::setw(4) << pasport.Series;
	std::cout << " ";
	std::cout << std::setfill('0') << std::setw(4) << pasport.Number;
}