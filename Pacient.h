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

Pacient GetsPacientData();									//�������� ���������
bool BoolFormatInputCard(int*);
void PutsPacientInfo(Pacient);								//������ ���������� � ��������
void GiveDiagnosisPacient(Diagnosis*, Pacient*);			//����� ������� � ��������� 
bool DiseaseOfPacient(std::string, Pacient);				//��������� �� ������� ������ �����������.