#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <iomanip>
#include <string>



//������� ��������� "������"
Doctor GetsDoctorData() {
	Doctor* doctor = new Doctor;

	printf(" <���� ���������� � �������>\n");
	SetFIOData(&doctor->Fio);

	std::cout << " ���������: ";
	std::getline(std::cin, doctor->dolgnost);
	
	std::cout << " <���� ��������>" << std::endl;
	return *doctor;
}




//����� ��������� "������"
void PutsDoctorInfo(Doctor doctor) {
	std::cout << " | ";
	PrintFIOInfo(doctor.Fio);
	std::cout << " | ";
	std::cout << std::setw(20) << doctor.dolgnost << " |" << std::endl;
}