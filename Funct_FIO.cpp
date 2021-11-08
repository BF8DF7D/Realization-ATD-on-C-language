#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <sstream>
#include "FIO.h"

void SetFIOData(FIO* fio) {
	bool False_Input_Value;
	do {
		std::cout << " ���: ";
		False_Input_Value = ItFalseInputFIO(fio);
		if (False_Input_Value) {
			std::cout << "\n <��� ������� �����������>" << std::endl;
		}
	} while (False_Input_Value);
}

bool BoolInputFIO(FIO* fio) {
	std::getline(std::cin, fio->Full_Name);
	std::cin.clear();
	std::stringstream Name_elements_stream(fio->Full_Name);
	std::string name_elements[] = { fio->Last_Name, fio->First_Name, fio->Patronymic };

	enum Limit_Value {
		Quantity_input_value = 3,
	};
	int Input_value_numbers = 0;
	for (std::string buffer; Name_elements_stream >> buffer; Input_value_numbers++) {
		if (Input_value_numbers < Quantity_input_value) 
			name_elements[Input_value_numbers] = buffer;
		else if (Input_value_numbers > Quantity_input_value)
			break;
	}

	bool False_Input_Value = Input_value_numbers != Quantity_input_value;

	return False_Input_Value;
}