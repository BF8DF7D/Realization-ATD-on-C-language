#include "Diagnosis.h"
#include <iostream>



//Струкутура "Диагноз"
Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis) {
	Diagnosis* un = (Diagnosis*)malloc(sizeof(Diagnosis));
	un->Tal = Dok;
	un->Dis = Dis;
	
	return *un;
}



//Печать структуры 
void PutsDiagnosisInfo(Diagnosis un) {
	Talon::Admission_Date* date = &un.Tal->Date;
	Talon::Admission_Time* time = &un.Tal->Time;

	printf(" Доктор: %s\n", un.Tal->Dok->Fio.Full_Name);
	printf(" Дата приёма: %d.%d.%d\n", date->day, date->mounth, date->year);
	printf(" Время приёма: %d.%d\n", time->hour, time->minutes);
	printf(" Кабинет: %d\n", un.Tal->kabinet);
	PutsGiseaseInfo(*(un.Dis));
}