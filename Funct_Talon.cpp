#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>




//Функция создания структуры "Талон"
Talon GetsTalonData(Doctor* med) {

	Talon* talon = (Talon*)malloc(sizeof(Talon));
	bool False_Input_Value;

	std::cout << " <Ввод информации о талоне>" << std::endl;

	//Дата приёма
	do {
		std::cout << " Дата приёма : ";
		False_Input_Value = SetDateData(&talon->Admission_Date);
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <Дата приёма введена некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	//Время приёма
	do {
		std::cout << " Время приёма: ";
		False_Input_Value = SetTimeData(&talon->Admission_Time);
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <Время приёма введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);


	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 999,
		Maximum_number = 23,
		Clean_input_stream = '\n'
	};
	//Номер кабинета
	do {
		std::cout << " Номер кабинета: ";
		False_Input_Value = scanf("%d", &talon->kabinet) != Quantity_input_value
			|| (talon->kabinet <= Minimum_value_for_number || talon->kabinet > Maximum_number)
			|| std::cin.get() != Clean_input_stream;
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <Номер кабинета введен некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	talon->Dok = med;

	std::cout << " <Ввод завершён>" << std::endl;
	return *talon; 
}




//Вывод структуры "Талон"
void PutsTalonInfo(Talon un) {

	printf("|%45s|", un.Dok->Fio.Full_Name);
	printf(" %02d.%02d.%04d|", un.Admission_Date.day, un.Admission_Date.mounth, un.Admission_Date.year);
	printf("%03d.%02d| %03d|\n", un.Admission_Time.hour, un.Admission_Time.minutes, un.kabinet);
}