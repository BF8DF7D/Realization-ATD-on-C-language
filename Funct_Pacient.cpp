#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Pacient.h"




//�������� ��������� Pacient
Pacient GetsPacientData() {

	Pacient* pacient = new Pacient;
	bool False_Input_Value;

	std::cout << " <���� ���������� � �������>" << std::endl;
	
	do {
		printf(" ���: ");
		flag = scanf("%14s%14s%14s", name->Last_Name, name->First_Name, name->Patronymic) != 3 //���� ��� �����
			|| getchar() != '\n'; //����� ����� �����
		if (flag == true) {
			while (getchar() != '\n'); //������� ������
			printf("\n <��� ������� �����������>\n");
		}
	} while (flag == true);

	char* name_elements[] = { name->Last_Name, name->First_Name, name->Patronymic }; //������ ���������� �� ��� �������� �����
	int fshag = 0; //����� ������� � ������ �����
	for (int elem = 0; elem < 3; elem++) { //���� ����� �������� �����
		for (int eshag = 0; eshag < strlen(name_elements[elem]); fshag++, eshag++) { //����������� ��������� � ������ ���.
			un->Legal.Fio.Full_Name[fshag] = name_elements[elem][eshag];
		}
		un->Legal.Fio.Full_Name[fshag++] = ' ';
	}
	un->Legal.Fio.Full_Name[fshag] = '\0';

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

	un->Diagnosis_point = 0;
	
	printf(" <���� ��������>\n");
	return *un;
}




//����� ��������� Pacient
void PutsPacientInfo(Pacient un) {
	Pacient::Legal_Data::FIO* name = &un.Legal.Fio;
	Pacient::Legal_Data::DATA_BRITH* brith = &un.Legal.Data_Brith;
	Pacient::Legal_Data::PASPORT* pasp = &un.Legal.Pasport; //������ ��������� � ����������� �������

	printf(" |%45s|", name->Full_Name);
	printf("%3d.%2d.%4d|", brith->day, brith->mounth, brith->year);
	printf("%5s%7s|%8s|", pasp->Series, pasp->Number, un.Legal.Medical_Card);

}




//��������� ������� � ��������
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* un) {
	un->Diagn[un->Diagnosis_point] = diagnos;
	un->Diagnosis_point++;
}



//��������� �� ������� ������ �����������.
bool DiseaseOfPacient(char* disease, Pacient un) {
	bool flag = false;
	for (int diagnosis = 0; diagnosis < un.Diagnosis_point && flag != true; diagnosis++) {
		flag = true;
//		if (strlen(disease) == strlen(un.Diagn[diagnosis]->disease->Name_Disease))
		{
			for (int char_point = 0; disease[char_point] != '\0' && flag != false; char_point++)
				if (un.Diagn[diagnosis]->disease->Name_Disease[char_point] != disease[char_point])					//��������� ������������ ��������
					flag = false;
		}
//		else
			flag = false;
	}
	return flag;

}