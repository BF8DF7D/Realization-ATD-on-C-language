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

Pacient GetsPacientData();									//�������� ���������
bool BoolFormatInputCard(int*);
void PrintPacientInfo(Pacient);								//������ ���������� � ��������
void GiveDiagnosisPacient(Diagnosis*, Pacient*);			//����� ������� � ��������� 
bool DiseaseOfPacient(std::string, Pacient);				//��������� �� ������� ������ �����������.