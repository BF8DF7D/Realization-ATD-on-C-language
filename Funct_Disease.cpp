#define _CRT_SECURE_NO_WARNINGS
#include "Disease.h"
#include <iostream>
#include <conio.h>




//Функция создания структуры "Заболевание"
Disease GetsDiseaseData() {

	Disease* un = (Disease*)malloc(sizeof(Disease));
	printf(" <Ввод информации о заболевании>\n");

	printf(" Наименование: ");
	scanf("%19s", un->Name_Disease);

	printf(" Симптомы.\n Вводите каждый новый симптом с новой строки.\n Для прекращения операции введите 0 ");

	while (getchar() != '\n');

	bool flag;
	char elem;
	int point = 0,
		memory_point = 0,		//Количество символов до записи нового числа.
		pointer_num = 0;

	un->Disease_Symptoms = (char*)calloc(40, sizeof(char));
	for (memory_point = 0; (elem = getchar()) != '0'; memory_point++) {
		if (memory_point % 40 == 0) {
			char* buffer = (char*)calloc(40 + memory_point, sizeof(char));
			for (int shag = 0; shag < memory_point; shag++) {

			}
		}
		if (elem == '\n') {

			*(un->Disease_Symptoms + memory_point) = '\0';
			un->Symtoms_pointer[pointer_num++] = un->Disease_Symptoms + point;

			point += (memory_point - point);
		}
		else
			*(un->Disease_Symptoms + memory_point) = elem;
	}

	return *un;
}