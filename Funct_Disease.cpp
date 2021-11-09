#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <conio.h>
#include <string>
#include <iomanip>




//Создание структуры "Заболевание"
Disease GetsDiseaseData() {

	Disease* disease = new Disease;
	std::cout << " <Ввод информации о заболевании>" << std::endl;
	std::cout << " Наименование: ";
	std::getline(std::cin, disease->Name_Disease);
	std::cin.clear();
	
	std::cout << " Симптомы.\n Вводите каждый новый симптом с новой строки.\n Для прекращения операции введите 0" << std::endl;

	for (int Input_value_number = 0, Exid_value = false; !Exid_value; Input_value_number++) {
		std::cout << " : ";
		std::getline(std::cin, disease->Disease_Symptoms[Input_value_number]);
		std::cin.clear();
		if (disease->Disease_Symptoms[Input_value_number].empty()) {
			Exid_value = true;
		}
	}
	
	return *disease;
}

//Печать структуры "Заболевание"
void PutsGiseaseInfo(Disease disease) {
	std::cout << " Наименование: " << disease.Name_Disease << std::endl;
	std::cout << " Симптомы: " << std::endl;
	
	enum Limit_Value {
		Symptoms_maximum_quantity = 50
	};
	
	int Input_value_number = 0;
	while (Input_value_number < Symptoms_maximum_quantity
		&& !disease.Disease_Symptoms[Input_value_number].empty()) {
		std::cout << " [" << std::setfill('0') << std::setw(2) << Input_value_number + 1 << "] ";
		std::cout << disease.Disease_Symptoms[Input_value_number++] << std::endl;
	}
}