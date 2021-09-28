#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Pacient.h"




//�������� ��������� Pacient
Pacient GetsPacientData() {

	Pacient* un = (Pacient*)malloc(sizeof(Pacient));
	bool flag;

	printf(" <���� ���������� � �������>\n");

	//���� ���

	Pacient::Legal_Data::FIO* name = &un->Legal.Fio; //������ ��������� � ���
	do {

		printf(" ���: ");
		flag = scanf("%14s%14s%14s", name->Last_Name, name->First_Name, name->Patronymic) != 3 //���� ��� �����
			|| getchar() != '\n'; //����� ����� �����
		if (flag == true) {
			while (getchar() != '\n'); //������� ������
			printf("\n <��� ������� �����������>\n");
		}
	} while (flag == true);

	//���� ���� ��������
	Pacient::Legal_Data::DATA_BRITH* brith = &un->Legal.Data_Brith; //������ ��������� � ����� ��������
	do {
		printf(" ���� ��������: ");
		flag = scanf("%d.%d.%d", &brith->day, &brith->mounth, &brith->year) != 3 //�������� 3 ������ ����� �����
			|| (brith->day > 31 || brith->day <= 0) //�������� ��� [0 < day <= 31]
			|| (brith->mounth > 12 || brith->mounth <= 0) //�������� ������ [0 < mounth <= 12]
			|| (brith->year > 9999 || brith->year <= 999) //�������� ���� [999 < year <= 9999]
			|| getchar() != '\n'; //����� ����� �����
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <���� �������� ������� �����������>\n");
		}
	} while (flag == true);

	//���� ���������� ������

	Pacient::Legal_Data::PASPORT* pasp = &un->Legal.Pasport; //������ ��������� � ����������� �������
	do {
		printf(" �������: ");
		flag = scanf("%4[0-9] %6[0-9]", pasp->Series, pasp->Number) != 2 //���� ��� �����
			|| strlen(pasp->Series) != 4 || strlen(pasp->Number) != 6 //�������� ���� ���
			|| getchar() != '\n'; //����� ����� �����
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <���������� ������ ������� �����������>\n");
		}
	} while (flag == true);

	do {
		printf(" ����� ���. �����: ");
		flag = scanf("%7[0-9, A-F]s", &un->Legal.Medical_Card) != 1
			|| strlen(un->Legal.Medical_Card) != 7
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n < ����� ���. ����� ����� �����������>\n");
		}
	} while (flag == true);

	printf("\n <���� ��������>\n");
	return *un;
}




//����� ��������� Pacient
void PutsPacientInfo(Pacient un) {
	Pacient::Legal_Data::FIO* name = &un.Legal.Fio;
	Pacient::Legal_Data::DATA_BRITH* brith = &un.Legal.Data_Brith;
	Pacient::Legal_Data::PASPORT* pasp = &un.Legal.Pasport; //������ ��������� � ����������� �������

	printf(" |%16s|%16s|%16s|", name->Last_Name, name->First_Name, name->Patronymic);
	printf("%3d.%2d.%4d|", brith->day, brith->mounth, brith->year);
	printf("%5s%7s|%8s|", pasp->Series, pasp->Number, un.Legal.Medical_Card);

}