#include "Diagnosis.h"
#include <iostream>



//���������� "�������"
Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis) {
	Diagnosis* un = (Diagnosis*)malloc(sizeof(Diagnosis));
	un->Tal = Dok;
	un->Dis = Dis;
	
	return *un;
}



//������ ��������� 
void PutsDiagnosisInfo(Diagnosis un) {
	Talon::Admission_Date* date = &un.Tal->Date;
	Talon::Admission_Time* time = &un.Tal->Time;

	printf(" ������: %s\n", un.Tal->Dok->Fio.Full_Name);
	printf(" ���� �����: %d.%d.%d\n", date->day, date->mounth, date->year);
	printf(" ����� �����: %d.%d\n", time->hour, time->minutes);
	printf(" �������: %d\n", un.Tal->kabinet);
	PutsGiseaseInfo(*(un.Dis));
}