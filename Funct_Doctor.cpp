#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>




//Созание структуры "Доктор"
Doctor GetsDoctorData() {
	Doctor* doctor = (Doctor*)malloc(sizeof(Doctor));
	bool flag;

	printf(" <Ввод информации о докторе>\n");
	
	bool False_Input_Value;
	do {
		std::cout << " ФИО: ";
		False_Input_Value = SetFIOData(&doctor->Fio);
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <ФИО введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);


	std::cout << " Должность: ";
	scanf("%19s", doctor->dolgnost);
	
	std::cout << " <Ввод завершён>" << std::endl;
	return *doctor;
}




//Вывод структуры "Доктор"
void PutsDoctorInfo(Doctor un) {
	printf(" |%45s|%20s|\n", un.Fio.Full_Name, un.dolgnost);
}