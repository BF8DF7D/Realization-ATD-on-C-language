#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>




//������� ��������� "������"
Doctor GetsDoctorData() {
	Doctor* doctor = (Doctor*)malloc(sizeof(Doctor));
	bool flag;

	printf(" <���� ���������� � �������>\n");
	
	bool False_Input_Value;
	do {
		std::cout << " ���: ";
		False_Input_Value = SetFIOData(&doctor->Fio);
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <��� ������� �����������>" << std::endl;
		}
	} while (False_Input_Value);


	std::cout << " ���������: ";
	scanf("%19s", doctor->dolgnost);
	
	std::cout << " <���� ��������>" << std::endl;
	return *doctor;
}




//����� ��������� "������"
void PutsDoctorInfo(Doctor un) {
	printf(" |%45s|%20s|\n", un.Fio.Full_Name, un.dolgnost);
}