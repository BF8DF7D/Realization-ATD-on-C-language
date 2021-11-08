#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Pacient.h"




//Создание структуры Pacient
Pacient GetsPacientData() {

	Pacient* pacient = new Pacient;
	bool False_Input_Value;

	std::cout << " <Ввод информации о пацинте>" << std::endl;
	
	do {
		printf(" ФИО: ");
		flag = scanf("%14s%14s%14s", name->Last_Name, name->First_Name, name->Patronymic) != 3 //Ввод трёх строк
			|| getchar() != '\n'; //Мусор после ввода
		if (flag == true) {
			while (getchar() != '\n'); //Очитска потока
			printf("\n <ФИО введено некорректно>\n");
		}
	} while (flag == true);

	char* name_elements[] = { name->Last_Name, name->First_Name, name->Patronymic }; //Массив указателей на все элементы имени
	int fshag = 0; //Номер символа в полной имени
	for (int elem = 0; elem < 3; elem++) { //Цикл смены элемента имени
		for (int eshag = 0; eshag < strlen(name_elements[elem]); fshag++, eshag++) { //Копирование элементов в полное имя.
			un->Legal.Fio.Full_Name[fshag] = name_elements[elem][eshag];
		}
		un->Legal.Fio.Full_Name[fshag++] = ' ';
	}
	un->Legal.Fio.Full_Name[fshag] = '\0';

	//Ввод Даты рождения
	Pacient::Legal_Data::DATA_BRITH* brith = &un->Legal.Data_Brith; //Адресс структуры с Датой рождения
	do {
		printf(" Дата рождения: ");
		flag = scanf("%d.%d.%d", &brith->day, &brith->mounth, &brith->year) != 3 //Введенны 3 целлых числа через
			|| (brith->day > 31 || brith->day <= 0) //Диапозон дня [0 < day <= 31]
			|| (brith->mounth > 12 || brith->mounth <= 0) //Диапозон месяца [0 < mounth <= 12]
			|| (brith->year > 9999 || brith->year <= 999) //Диапозон года [999 < year <= 9999]
			|| getchar() != '\n'; //Мусор после ввода
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <Дата рождения введена некорректно>\n");
		}
	} while (flag == true);

	//Ввод паспортных данных

	Pacient::Legal_Data::PASPORT* pasp = &un->Legal.Pasport; //Адресс структуры с Паспортными данными
	do {
		printf(" Паспорт: ");
		flag = scanf("%4[0-9] %6[0-9]", pasp->Series, pasp->Number) != 2 //Ввод трёх строк
			|| strlen(pasp->Series) != 4 || strlen(pasp->Number) != 6 //Проверка длин сим
			|| getchar() != '\n'; //Мусор после ввода
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n <Паспортные данные введены некорректно>\n");
		}
	} while (flag == true);

	do {
		printf(" Номер мед. карты: ");
		flag = scanf("%7[0-9, A-F]s", &un->Legal.Medical_Card) != 1
			|| strlen(un->Legal.Medical_Card) != 7
			|| getchar() != '\n';
		if (flag == true) {
			while (getchar() != '\n');
			printf("\n < Номер мед. карты введён некорректно>\n");
		}
	} while (flag == true);

	un->Diagnosis_point = 0;
	
	printf(" <Ввод завершён>\n");
	return *un;
}




//Вывод стурктуры Pacient
void PutsPacientInfo(Pacient un) {
	Pacient::Legal_Data::FIO* name = &un.Legal.Fio;
	Pacient::Legal_Data::DATA_BRITH* brith = &un.Legal.Data_Brith;
	Pacient::Legal_Data::PASPORT* pasp = &un.Legal.Pasport; //Адресс структуры с Паспортными данными

	printf(" |%45s|", name->Full_Name);
	printf("%3d.%2d.%4d|", brith->day, brith->mounth, brith->year);
	printf("%5s%7s|%8s|", pasp->Series, pasp->Number, un.Legal.Medical_Card);

}




//Привязать диагноз к пациенту
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* un) {
	un->Diagn[un->Diagnosis_point] = diagnos;
	un->Diagnosis_point++;
}



//Переносил ли пациент данное заболевание.
bool DiseaseOfPacient(char* disease, Pacient un) {
	bool flag = false;
	for (int diagnosis = 0; diagnosis < un.Diagnosis_point && flag != true; diagnosis++) {
		flag = true;
//		if (strlen(disease) == strlen(un.Diagn[diagnosis]->disease->Name_Disease))
		{
			for (int char_point = 0; disease[char_point] != '\0' && flag != false; char_point++)
				if (un.Diagn[diagnosis]->disease->Name_Disease[char_point] != disease[char_point])					//Сравнение наименований болезней
					flag = false;
		}
//		else
			flag = false;
	}
	return flag;

}