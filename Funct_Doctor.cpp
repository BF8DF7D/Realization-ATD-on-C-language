#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <conio.h>




//������� ��������� "������"
Doctor GetsDoctorData() {
	Doctor* un = (Doctor*)malloc(sizeof(Doctor));
	bool flag;

	printf(" <���� ���������� � �������>\n");

	Doctor::FIO* name = &un->Fio;
	do {
		printf(" ���: ");
		flag = scanf("%14s%14s%14s", name->Last_Name, name->First_Name, name->Patronymic) != 3
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <��� ������� �����������>\n");
		}
	} while (flag == true);

	char* name_elements[] = { name->Last_Name, name->First_Name, name->Patronymic }; //������ ���������� �� ��� �������� �����
	int fshag = 0; //����� ������� � ������ �����
	for (int elem = 0; elem < 3; elem++) { //���� ����� �������� �����
		for (int eshag = 0; eshag < strlen(name_elements[elem]); fshag++, eshag++) { //����������� ��������� � ������ ���.
			un->Fio.Full_Name[fshag] = name_elements[elem][eshag];
		}
		un->Fio.Full_Name[fshag++] = ' ';
	}
	un->Fio.Full_Name[fshag] = '\0';


	printf(" ���������: ");
	scanf("%19s", un->dolgnost);
	
	printf(" <���� ��������>\n");
	return *un;
}




//����� ��������� "������"
void PutsDoctorInfo(Doctor un) {
	printf(" |%45s|%20s|\n", un.Fio.Full_Name, un.dolgnost);
}