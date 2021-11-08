#include "Pasport.h"

bool SetPasportData(Pasport* pasport) {
	enum Limit_Value {
		Quantity_inpyt_value = 2,
		Minimum_value_for_all = 1,
		Maximum_for_series = 9999,
		Maximum_for_number = 999999,
		Clean_input_stream = '\n'
	};

	bool False_Input_Value = scanf("%d %d", &pasport->Number, &pasport->Series) != Quantity_inpyt_value
		|| (pasport->Series < Minimum_value_for_all || pasport->Series > Maximum_for_series)
		|| (pasport->Number < Minimum_value_for_all || pasport->Number > Maximum_for_number)
		|| std::cin.get() != Clean_input_stream;
	std::cin.clear();

	return False_Input_Value;
}