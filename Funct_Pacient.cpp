#define _CRT_SECURE_NO_WARNINGS
#include "Pacient.h"
#include <sstream>
#include <iostream>
#include <string>



//Создание структуры Pacient
Pacient GetsPacientData() {

	Pacient* pacient = new Pacient;
	std::cout << " <Ввод информации о пацинте>" << std::endl;
	
	SetFIOData(&pacient->Fio);
	SetDateData(&pacient->Data_Brith);
	SetPasportData(&pacient->pasport);

	bool False_Input_Value;
	do {
		False_Input_Value = BoolInputCard(&pacient->Medical_Card);
		if (False_Input_Value) {
			std::cout << "\n < Номер мед. карты введён некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	pacient->Diagnosis_point = 0;
	
	std::cout << " <Ввод завершён>" << std::endl;
	return *pacient;
}

bool BoolInputCard(int* number) {
	enum Limit_Value {
		Minimum_number = 0x1,
		Maximum_number = 0xFFFFFFF,
		Clean_input_stream = '\n'
	};
	bool False_Input_Value;

	std::cout << " Номер мед. карты: ";
	std::cin >> *number;
	False_Input_Value = (*number < Minimum_number || *number > Maximum_number)
		|| std::cin.get() != Clean_input_stream;
	std::cin.clear();

	return False_Input_Value;
}


/*
//Вывод стурктуры Pacient
void PutsPacientInfo(Pacient un) {
	Pacient::Legal_Data::FIO* name = &un.Legal.Fio;
	Pacient::Legal_Data::DATA_BRITH* brith = &un.Legal.Data_Brith;
	Pacient::Legal_Data::PASPORT* pasp = &un.Legal.Pasport; //Адресс структуры с Паспортными данными

	printf(" |%45s|", name->Full_Name);
	printf("%3d.%2d.%4d|", brith->day, brith->mounth, brith->year);
	printf("%5s%7s|%8s|", pasp->Series, pasp->Number, un.Legal.Medical_Card);

}
*/



//Привязать диагноз к пациенту
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* pacient) {
	pacient->Diagnosis_History[pacient->Diagnosis_point] = diagnos;
	pacient->Diagnosis_point++;
}



//Переносил ли пациент данное заболевание.
bool DiseaseOfPacient(std::string Name_Disease, Pacient pacient) {
	bool Serched_disease_is_present = false;
	for (Diagnosis* diagnosis : pacient.Diagnosis_History) {
		if (diagnosis->disease->Name_Disease == Name_Disease) {
			Serched_disease_is_present = true;
			break;
		}
	}
	return Serched_disease_is_present;

}