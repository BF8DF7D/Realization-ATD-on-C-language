#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>
#include <iomanip>




//������� �������� ��������� "�����"
Talon GetsTalonData(Doctor* med) {

	Talon* talon = new Talon;
	bool False_Input_Value;

	std::cout << " <���� ���������� � ������>" << std::endl;
	SetDateData(&talon->Admission_Date);
	SetTimeData(&talon->Admission_Time);
	
	do {
		std::cout << " ����� ��������: ";
		False_Input_Value = GetKabinet(&talon->kabinet);
		if (False_Input_Value) {
			std::cout << "\n <����� �������� ������ �����������>" << std::endl;
		}
	} while (False_Input_Value);

	talon->Dok = med;

	std::cout << " <���� ��������>" << std::endl;
	return *talon; 
}

bool GetKabinet(int* kabinet ) {
	enum Limit_Value_for_Number {
		Quantity_input_value = 1,
		Minimum_value_for_number = 0,
		Maximum_number = 999,
		Clean_input_stream = '\n'
	};
	bool False_Input_Value = scanf("%d", kabinet) != Quantity_input_value
		|| (*kabinet <= Minimum_value_for_number || *kabinet > Maximum_number)
		|| std::cin.get() != Clean_input_stream;
	std::cin.clear();

	return False_Input_Value;
}


//����� ��������� "�����"
void PutsTalonInfo(Talon talon) {
	std::cout << " | "; 
	PrintFIOInfo(talon.Dok->Fio);
	std::cout << " | ";
	PrintDateInfo(talon.Admission_Date);
	std::cout << " | ";
	PrintTimeInfo(talon.Admission_Time);
	std::cout << " | ";
	std::cout.fill('0');
	std::cout << std::cout.fill('0') << talon.kabinet << std::setw(3) << " |";
	
}