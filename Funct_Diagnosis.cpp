#include "Diagnosis.h"
#include <iostream>
#include <iomanip>



//Струкутура "Диагноз"
Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis) {
	Diagnosis* diagnosis = (Diagnosis*)malloc(sizeof(Diagnosis));
	diagnosis->talon = Dok;
	diagnosis->disease = Dis;
	
	return *diagnosis;
}



//Печать структуры 
void PutsDiagnosisInfo(Diagnosis diagnosis) {
	Date* date = &diagnosis.talon->Admission_Date;
	Time* time = &diagnosis.talon->Admission_Time;

	std::cout << " Доктор: " << std::setw(45) << diagnosis.talon->Dok->Fio.Full_Name << std::endl;

	std::cout << " Дата приёма: " << std::setw(2) << std::cout.fill('0') << date->day << ".";
	std::cout << std::setw(2) << std::cout.fill('0') << date->mounth << ".";
	std::cout << std::setw(4) << date->year << std::endl;

	std::cout << " Время приёма: " << std::setw(2) << std::cout.fill('0') << time->hour << ".";
	std::cout << std::setw(2) << std::cout.fill('0') << time->minutes << std::endl;

	std::cout << std::setw(3) << std::cout.fill('0') << diagnosis.talon->kabinet << std::endl;
	
	PutsGiseaseInfo(*diagnosis.disease);
}