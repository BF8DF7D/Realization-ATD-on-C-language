#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <sstream>
#include "FIO.h"

bool SetFIOData(FIO* fio) {
	enum Limit_Value {
		Quantity_input_value = 3,
	};

	std::getline(std::cin, fio->Full_Name);
	std::stringstream stream(fio->Full_Name);
	std::string name_elements[] = { fio->Last_Name, fio->First_Name, fio->Patronymic };

	int Input_value_numbers;
	for (Input_value_numbers = 0; !stream.eof(); Input_value_numbers++) {
		if (Input_value_numbers != Quantity_input_value)
			stream >> name_elements[Input_value_numbers];
		else
			break;
	}

	bool False_Input_Value = (Input_value_numbers != Quantity_input_value 
		|| (Input_value_numbers == Quantity_input_value && !stream.eof()));

	return False_Input_Value;
}