#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <iostream>




//������� �������� ��������� "�����������"
Disease GetsDiseaseData() {
	
	Disease* un = (Disease*)malloc(sizeof(Disease));
	printf(" <���� ���������� � �����������>\n");

	printf(" ������������: ");
	scanf("%19s", un->Name_Disease);

	printf(" ��������.\n ������� ������ ����� ������� � ����� ������.\n ��� ����������� �������� ������� 0 ");

	bool flag;
	char buffer[30];
	int memory_point = 0,		//���������� �������� 
		pointer_num = 0;

	un->Disease_Symptoms = (char*)malloc(sizeof(char));
	
	do {
		printf("\n : ");
		scanf("%19s", buffer);

		un->Disease_Symptoms = (char*)realloc(un->Disease_Symptoms, (memory_point + strlen(buffer) + 1) * sizeof(char));
		un->Symtoms_pointer[pointer_num++] = un->Disease_Symptoms + memory_point;
		
		printf("%d", strlen(un->Disease_Symptoms));
		int shag = 0;
		for (; shag < strlen(buffer); shag++) 
			*(un->Disease_Symptoms + memory_point + shag) = *(buffer + shag);
		*(un->Disease_Symptoms + memory_point + shag) = '\0';

		memory_point += strlen(buffer) + 1;

	} while (1);
}