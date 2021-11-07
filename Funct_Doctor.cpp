#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>



//Созание структуры "Доктор"
Doctor GetsDoctorData() {
	Doctor* doctor = new Doctor;

	printf(" <Ввод информации о докторе>\n");
	
	bool False_Input_Value;
	do {
		std::cout << " ФИО: ";
		False_Input_Value = SetFIOData(&doctor->Fio);
		if (False_Input_Value) {
			std::cin.clear();
			std::cout << "\n <ФИО введено некорректно>" << std::endl;
		}
	} while (False_Input_Value);


	std::cout << " Должность: ";
	std::getline(std::cin, doctor->dolgnost);
	
	std::cout << " <Ввод завершён>" << std::endl;
	return *doctor;
}




//Вывод структуры "Доктор"
void PutsDoctorInfo(Doctor doctor) {
	std::cout << " |" << std::setw(45) << doctor.Fio.Full_Name << " | ";
	std::cout << std::setw(20) << doctor.dolgnost << " |" << std::endl;
}