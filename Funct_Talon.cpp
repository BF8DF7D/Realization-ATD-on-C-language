#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>




//������� �������� ��������� "�����"
Talon GetsTalonData(Doctor* med) {

	Talon* talon = (Talon*)malloc(sizeof(Talon));
	bool False_Input_Value;

	std::cout << " <���� ���������� � ������>" << std::endl;

	//���� �����
	do {
		std::cout << " ���� ����� : ";
		False_Input_Value = SetDateData(&talon->Admission_Date);
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <���� ����� ������� �����������>" << std::endl;
		}
	} while (False_Input_Value);

	//����� �����
	do {
		std::cout << " ����� �����: ";
		False_Input_Value = SetTimeData(&talon->Admission_Time);
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <����� ����� ������� �����������>" << std::endl;
		}
	} while (False_Input_Value);


	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 999,
		Maximum_number = 23,
		Clean_input_stream = '\n'
	};
	//����� ��������
	do {
		std::cout << " ����� ��������: ";
		False_Input_Value = scanf("%d", &talon->kabinet) != Quantity_input_value
			|| (talon->kabinet <= Minimum_value_for_number || talon->kabinet > Maximum_number)
			|| std::cin.get() != Clean_input_stream;
		if (False_Input_Value) {
			while (std::cin.get() != '\n');
			std::cout << "\n <����� �������� ������ �����������>" << std::endl;
		}
	} while (False_Input_Value);

	talon->Dok = med;

	std::cout << " <���� ��������>" << std::endl;
	return *talon; 
}




//����� ��������� "�����"
void PutsTalonInfo(Talon talon) {
	std::cout << " " << std::setw(45) << talon.Dok->Fio.Full_Name << "| ";
	
	std::cout << std::setw(2) << std::cout.fill('0') << talon.Admission_Date.day << ".";
	std::cout << std::setw(2) << std::cout.fill('0') << talon.Admission_Date.mounth << ".";
	std::cout << std::setw(4) << talon.Admission_Date.year << "| ";
	
	std::cout << std::setw(2) << std::cout.fill('0') << talon.Admission_Time.hour << ".";
	std::cout << std::setw(2) << std::cout.fill('0') << talon.Admission_Time.minutes << "| ";

	std::cout << std::setw(3) << std::cout.fill('0') << talon.kabinet << "|";
}