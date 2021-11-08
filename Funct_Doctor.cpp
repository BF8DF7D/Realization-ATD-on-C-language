#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>



//������� ��������� "������"
Doctor GetsDoctorData() {
	Doctor* doctor = new Doctor;

	printf(" <���� ���������� � �������>\n");
	
	bool False_Input_Value;
	do {
		std::cout << " ���: ";
		False_Input_Value = SetFIOData(&doctor->Fio);
		if (False_Input_Value) {
			std::cin.clear();
			std::cout << "\n <��� ������� �����������>" << std::endl;
		}
	} while (False_Input_Value);


	std::cout << " ���������: ";
	std::getline(std::cin, doctor->dolgnost);
	
	std::cout << " <���� ��������>" << std::endl;
	return *doctor;
}




//����� ��������� "������"
void PutsDoctorInfo(Doctor doctor) {
	std::cout << " |" << std::setw(45) << doctor.Fio.Full_Name << " | ";
	std::cout << std::setw(20) << doctor.dolgnost << " |" << std::endl;
}