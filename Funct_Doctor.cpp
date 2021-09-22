#define _CRT_SECURE_NO_WARNINGS
#include "Doctor.h"
#include <iostream>
#include <conio.h>




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

	char* name_elements[] = { name->Last_Name, name->First_Name, name->Patronymic }; //Массив указателей на все элементы имени
	int fshag = 0; //Номер символа в полной имени
	for (int elem = 0; elem < 3; elem++) { //Цикл смены элемента имени
		for (int eshag = 0; eshag < strlen(name_elements[elem]); fshag++, eshag++) { //Копирование элементов в полное имя.
			un->Fio.Full_Name[fshag] = name_elements[elem][eshag];
		}
		un->Fio.Full_Name[fshag++] = ' ';
	}
	un->Fio.Full_Name[fshag] = '\0';


	printf(" Должность: ");
	scanf("%19s", un->dolgnost);
	
	printf(" <Ввод завершён>\n");
	return *un;
}




//Вывод структуры "Доктор"
void PutsDoctorInfo(Doctor un) {
	printf(" |%45s|%20s|\n", un.Fio.Full_Name, un.dolgnost);
}