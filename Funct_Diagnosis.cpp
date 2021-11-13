#include "Diagnosis.h"
#include <iostream>
#include <iomanip>



//���������� "�������"
Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis) {
	Diagnosis* diagnosis = new Diagnosis;
	diagnosis->talon = Dok;
	diagnosis->disease = Dis;
	
	return *diagnosis;
}



//������ ��������� 
void PutsDiagnosisInfo(Diagnosis diagnosis) {
	Date* date = &diagnosis.talon->Admission_Date;
	Time* time = &diagnosis.talon->Admission_Time;

	std::cout << " ������: " << diagnosis.talon->Dok->Fio.Full_Name << std::endl;
	std::cout << " ���� �����: ";
	PrintDateInfo(diagnosis.talon->Admission_Date);
	std::cout << std::endl;
	std::cout << " ����� �����: ";
	PrintTimeInfo(diagnosis.talon->Admission_Time);
	std::cout << std::endl;
	std::cout << " ����� ��������: ";
	std::cout << std::setfill('0') << std::setw(3) << diagnosis.talon->kabinet << std::endl;
	std::cout.fill(' ');

	PutsGiseaseInfo(*diagnosis.disease);
}