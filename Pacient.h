#include "Diagnosis.h"
#include "Pasport.h"

struct Pacient {
	FIO Fio;
	Date Data_Brith;
	Pasport pasport;
	int Medical_Card; 

	Diagnosis* Diagnosis_History[30];
	int Diagnosis_point;
};

Pacient GetsPacientData();										//Создание структуры
bool BoolInputCard(int* number);
void PutsPacientInfo(Pacient);									//Печать информации о пациенте
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* un);		//Связь дигноза с пациентом 
bool DiseaseOfPacient(char disease[], Pacient un);				//Переносил ли пациент данное заболевание.