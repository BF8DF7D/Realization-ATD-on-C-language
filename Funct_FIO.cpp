#include "FIO.h"

bool SetFIOData(FIO* fio) {
	enum Limit_Value {
		Quantity_input_value = 3,
		Clean_input_stream = '\n'
	};

	bool False_Input_Value = scanf("%14s %14s %14s", fio->Last_Name, fio->First_Name, fio->Patronymic) != Quantity_input_value
		|| std::cin.get() != Clean_input_stream;

	if (False_Input_Value) {
		return False_Input_Value;
	} 
	else {
		std::string name_elements[] = { fio->Last_Name, fio->First_Name, fio->Patronymic }; 
		for (std::string elements : name_elements) {
			fio->Full_Name += elements + " ";
		}
		return False_Input_Value;
	}
	
}