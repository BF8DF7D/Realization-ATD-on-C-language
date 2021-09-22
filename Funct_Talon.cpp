#define _CRT_SECURE_NO_WARNINGS
#include "Talon.h"
#include <iostream>




//Функция создания структуры "Талон"
Talon GetsTalonData(Doctor* med) {

	Talon* un = (Talon*)malloc(sizeof(Talon));
	bool flag;

	printf(" <Ввод информации о докторе>\n");

	//Дата приёма
	Talon::Admission_Date* date = &un->Date;
	do {
		printf(" Дата приёма: ");
		flag = scanf("%d.%d.%d", &date->day, &date->mounth, &date->year) != 3
			|| (date->day <= 0 || date->day > 31)
			|| (date->mounth <= 0 || date->mounth > 12)
			|| (date->year <= 999 || date->year > 9999)
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <Дата приёма введена некорректно>\n");
		}
	} while (flag == true);

	//Время приёма
	Talon::Admission_Time* time = &un->Time;
	do {
		printf(" Время приёма: ");
		flag = scanf("%d.%d", &time->hour, &time->minutes) != 2
			|| (time->hour < 0 || time->hour > 23)
			|| (time->minutes < 0 || time->minutes > 59)
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <Время приёма введено некорректно>\n");
		}
	} while (flag == true);

	//Номер кабинета
	do {
		printf(" Номер кабинета: ");
		flag = scanf("%d", &un->kabinet) != 1
			|| (un->kabinet <= 0 || un->kabinet > 500)
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <Номер кабинета введен некорректно>\n");
		}
	} while (flag == true);

	un->name = med;

	return *un; 
}




//Вывод структуры "Талон"
void PutsTalonInfo(Talon un) {
	Talon::Admission_Date* date = &un.Date;
	Talon::Admission_Time* time = &un.Time;
	Doctor::FIO* name = &un.name->Fio;

	printf("|%15s|%15s|%15s|", name->Last_Name, name->First_Name, name->Patronymic);
	printf("%3d.%2d.%4d|", date->day, date->mounth, date->year);
	printf("%3d.%2d|%4d|\n", time->hour, time->minutes, un.kabinet);
}