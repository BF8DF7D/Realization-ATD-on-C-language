#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>




//Созание структуры "Доктор"
Doctor GetsDoctorData() {
	Doctor* un = (Doctor*)malloc(sizeof(Doctor));
	bool flag;

	printf(" <Ввод информации о докторе>\n");

	Doctor::FIO* name = &un->Fio;
	do {
		printf(" ФИО: ");
		flag = scanf("%14s%14s%14s", name->Last_Name, name->First_Name, name->Patronymic) != 3
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <ФИО введено некорректно>\n");
		}
	} while (flag == true);

	printf(" Должность: ");
	scanf("%19s", un->dolgnost);
	
	printf(" <Ввод завершён>\n");
	return *un;
}




//Вывод структуры "Доктор"
void PutsDoctorInfo(Doctor x) {
	Doctor::FIO* name = &x.Fio;
	printf(" |%15s|%15s|%15s|%20s|\n", name->Last_Name, name->First_Name, name->Patronymic, x.dolgnost);
}