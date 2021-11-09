#include "Diagnosis.h"
#include <iostream>
#include <iomanip>



//Струкутура "Диагноз"
Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis) {
	Diagnosis* diagnosis = new Diagnosis;
	diagnosis->talon = Dok;
	diagnosis->disease = Dis;
	
	return *diagnosis;
}



//Печать структуры 
void PutsDiagnosisInfo(Diagnosis diagnosis) {
	Date* date = &diagnosis.talon->Admission_Date;
	Time* time = &diagnosis.talon->Admission_Time;

	std::cout << " Доктор: " << diagnosis.talon->Dok->Fio.Full_Name << std::endl;
	std::cout << " Дата приёма: ";
	PrintDateInfo(diagnosis.talon->Admission_Date);
	std::cout << std::endl;
	std::cout << " Время приёма: ";
	PrintTimeInfo(diagnosis.talon->Admission_Time);
	std::cout << std::endl;
	std::cout << " Номер кабинета: ";
	std::cout << std::setfill('0') << std::setw(3) << diagnosis.talon->kabinet << std::endl;
	std::cout.fill(' ');

	PutsGiseaseInfo(*diagnosis.disease);
}