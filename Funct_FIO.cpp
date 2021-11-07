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
	
	int Quantity_value;
	for (Quantity_value = 0; !stream.eof(); Quantity_value++) {
		if (Quantity_value != Quantity_input_value)
			stream >> name_elements[Quantity_value];
	}
	
	bool False_Input_Value = (Quantity_value != Quantity_input_value);

	return False_Input_Value;
}