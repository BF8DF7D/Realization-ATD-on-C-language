#include "Diagnosis.h"

struct Pacient {
	//����������� ������
	struct Legal_Data {
		//��� ��������
		struct FIO {
			char Last_Name[15], //�������
				First_Name[15], //���
				Patronymic[15], //��������
				Full_Name[45];
		} Fio;

		//���� ��������
		struct DATA_BRITH {
			int day, //����
				mounth, //�����
				year; //���
		} Data_Brith;

		//���������� ������
		struct PASPORT {
			char Series[5], //C���� ������ ��������
				Number[7]; //���������� ����� �������� � �����
		} Pasport;

		char Medical_Card[8]; //����� ����������� �����

	} Legal;

	Diagnosis* Diagn[30];
};

Pacient GetsPacientData();
void PutsPacientInfo(Pacient);
