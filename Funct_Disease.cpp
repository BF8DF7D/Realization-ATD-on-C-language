#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <iostream>
#include <conio.h>




//�������� ��������� "�����������"
Disease GetsDiseaseData() {

	Disease* un = (Disease*)malloc(sizeof(Disease));
	printf(" <���� ���������� � �����������>\n");

	printf(" ������������: ");
	scanf("%19s", un->Name_Disease);

	printf(" ��������.\n ������� ������ ����� ������� � ����� ������.\n ��� ����������� �������� ������� 0\n");

	while (getchar() != '\n');

	for (int memory_point = 0, flag = true; flag != false; memory_point++) {
		printf(" : ");
		gets_s(un->Disease_Symptoms[memory_point]);
		if (un->Disease_Symptoms[memory_point][0] == '0') {
			un->Disease_Symptoms[memory_point][0] = '\0';
			flag = false;
		}
	}

	return *un;
}




//������ ��������� "�����������"
void PutsGiseaseInfo(Disease un) {
	printf(" ������������: %s\n", un.Name_Disease);
	printf(" ��������: \n");
	for (int memory_point = 0; un.Disease_Symptoms[memory_point][0] != '\0'; memory_point++)
		printf(" [%2d] %s\n", memory_point, un.Disease_Symptoms[memory_point]);
}