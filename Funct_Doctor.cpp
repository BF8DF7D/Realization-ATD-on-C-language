#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>




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

	printf(" ���������: ");
	scanf("%19s", un->dolgnost);
	
	printf(" <���� ��������>\n");
	return *un;
}




//����� ��������� "������"
void PutsDoctorInfo(Doctor x) {
	Doctor::FIO* name = &x.Fio;
	printf(" |%15s|%15s|%15s|%20s|\n", name->Last_Name, name->First_Name, name->Patronymic, x.dolgnost);
}