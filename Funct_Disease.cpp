#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <conio.h>
#include <string>




//�������� ��������� "�����������"
Disease GetsDiseaseData() {

	Disease* disease = new Disease;
	std::cout << " <���� ���������� � �����������>" << std::endl;
	std::cout << " ������������: ";
	std::getline(std::cin, disease->Name_Disease);
//	std::cin;

	std::cout << " ��������.\n ������� ������ ����� ������� � ����� ������.\n ��� ����������� �������� ������� 0" << std::endl;

	for (int Input_value_number = 0, Exid_value = false; !Exid_value; Input_value_number++) {
		std::cout << " : ";
		std::getline(std::cin, disease->Disease_Symptoms[Input_value_number]);
		if (disease->Disease_Symptoms[Input_value_number].empty()) {
			Exid_value = true;
		}
	}

	return *disease;
}




//������ ��������� "�����������"
void PutsGiseaseInfo(Disease disease) {
	std::cout << " ������������: " << disease.Name_Disease << std::endl;
	std::cout << " ��������: " << std::endl;
	
	int Input_value_number = 0;
	while (Input_value_number < 50 && !disease.Disease_Symptoms[Input_value_number].empty()) {
		std::cout << disease.Disease_Symptoms[Input_value_number++] << std::endl;
	}
}