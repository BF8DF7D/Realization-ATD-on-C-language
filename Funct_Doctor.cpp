#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;

//Созание структуры "Доктор"
Doctor GetsDoctorData() {
	Doctor* doctor = new Doctor;

	printf(" <Ввод информации о докторе>\n");
	SetFIOData(&doctor->Fio);

	std::cout << " Должность: ";
	std::getline(std::cin, doctor->dolgnost);
	
	std::cout << " <Ввод завершён>" << std::endl;
	return *doctor;
}




//Вывод структуры "Доктор"
void PutsDoctorInfo(Doctor doctor) {
	std::cout << " | ";
	std::cout << std::setfill(' ') << std::setw(45) << doctor.Fio.Full_Name;
	std::cout << " | ";
	std::cout << std::setw(20) << doctor.dolgnost << " |" << std::endl;
}