#include "Diagnosis.h"
#include "Pasport.h"

struct Pacient {
	FIO Fio;
	Date Data_Brith;
	Pasport pasport;
	int Medical_Card; 

	Diagnosis* Diagnosis_History[51];
	int Diagnosis_point = 0;
};

Pacient GetsPacientData();									//Создание структуры
bool BoolFormatInputCard(int*);
void PrintPacientInfo(Pacient);								//Печать информации о пациенте
void GiveDiagnosisPacient(Diagnosis*, Pacient*);			//Связь дигноза с пациентом 
bool DiseaseOfPacient(std::string, Pacient);				//Переносил ли пациент данное заболевание.