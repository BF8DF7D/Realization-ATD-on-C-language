#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <conio.h>
#include <string>
#include <iomanip>




//�������� ��������� "�����������"
Disease GetsDiseaseData() {

	Disease* disease = new Disease;
	std::cout << " <���� ���������� � �����������>" << std::endl;
	std::cout << " ������������: ";
	std::getline(std::cin, disease->Name_Disease);
	std::cin.clear();
	
	std::cout << " ��������.\n ������� ������ ����� ������� � ����� ������.\n ��� ����������� �������� ������� Enter" << std::endl;
	
	for (std::string& symptom : disease->Disease_Symptoms) {
		std::cout << " : ";
		std::getline(std::cin, symptom);
		std::cin.clear();
		if (symptom.empty())
			break;
	}
	
	return *disease;
}

//������ ��������� "�����������"
void PutsGiseaseInfo(Disease disease) {
	std::cout << " ������������: " << disease.Name_Disease << std::endl;
	std::cout << " ��������: " << std::endl;
	
	int Input_value_number = 0;
	std::string Empty_value_of_symptom = "";
	for (std::string symptom : disease.Disease_Symptoms) {
		if (symptom == Empty_value_of_symptom)
			break;
		std::cout << " [" << std::setfill('0') << std::setw(2) << ++Input_value_number << "] ";
		std::cout << symptom << std::endl;
	}
	std::cout.fill(' ');
}