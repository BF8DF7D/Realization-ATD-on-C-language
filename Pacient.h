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

Pacient GetsPacientData();										//�������� ���������
bool BoolInputCard(int* number);
void PutsPacientInfo(Pacient);									//������ ���������� � ��������
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* un);		//����� ������� � ��������� 
bool DiseaseOfPacient(char disease[], Pacient un);				//��������� �� ������� ������ �����������.