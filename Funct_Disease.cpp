#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <iostream>
#include <conio.h>




//Создание структуры "Заболевание"
Disease GetsDiseaseData() {

	Disease* un = (Disease*)malloc(sizeof(Disease));
	printf(" <Ввод информации о заболевании>\n");

	printf(" Наименование: ");
	scanf("%19s", un->Name_Disease);

	printf(" Симптомы.\n Вводите каждый новый симптом с новой строки.\n Для прекращения операции введите 0\n");

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




//Печать структуры "Заболевание"
void PutsGiseaseInfo(Disease un) {
	printf(" Наименование: %s\n", un.Name_Disease);
	printf(" Симптомы: \n");
	for (int memory_point = 0; un.Disease_Symptoms[memory_point][0] != '\0'; memory_point++)
		printf(" [%2d] %s\n", memory_point, un.Disease_Symptoms[memory_point]);
}