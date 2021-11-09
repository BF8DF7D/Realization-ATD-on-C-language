#define _CRT_SECURE_NO_WARNINGS
#include "Pacient.h"
#include <iostream>
#include <iomanip>



//Создание структуры Pacient
Pacient GetsPacientData() {

	Pacient* pacient = new Pacient;
	std::cout << " <Ввод информации о пацинте>" << std::endl;
	
	SetFIOData(&pacient->Fio);
	SetDateData(&pacient->Data_Brith);
	SetPasportData(&pacient->pasport);

	bool False_Input_Value;
	do {
		False_Input_Value = BoolFormatInputCard(&pacient->Medical_Card);
		if (False_Input_Value) {
			std::cout << "\n < Номер мед. карты введён некорректно>" << std::endl;
		}
	} while (False_Input_Value);

	pacient->Diagnosis_point = 0;
	
	std::cout << " <Ввод завершён>" << std::endl;
	return *pacient;
}

bool BoolFormatInputCard(int* number) {
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



//Вывод стурктуры Pacient
void PrintPacientInfo(Pacient pacient) {

	std::cout << " <Персональные данные>" << std::endl;
	std::cout << " ФИО пациента            : ";
	PrintFIOInfo(pacient.Fio);
	std::cout << std::endl;
	std::cout << " Серия и номер паспорта  : ";
	PrintPasportInfo(pacient.pasport);
	std::cout << std::endl;
	std::cout << " Дата рождения           : ";
	PrintDateInfo(pacient.Data_Brith);
	std::cout << std::endl;
	std::cout << " Номер медецинской карты : ";
	std::cout << std::uppercase << std::hex << pacient.Medical_Card ;
	std::cout << " <Краткая история болезни>" << std::endl;

	if (pacient.Diagnosis_point > 0) {
		std::cout << " Общее число зарегистрированных заболеваний: " << pacient.Diagnosis_point << std::endl;
		std::cout << "    Наименование болезни :       Дата : Время :" << std::endl;

		for (Diagnosis* diagnosis : pacient.Diagnosis_History) {
			std::cout << " ";
			std::cout << std::setw(23) << diagnosis->disease->Name_Disease;
			std::cout << " : ";
			PrintDateInfo(diagnosis->talon->Admission_Date);
			std::cout << " : ";
			PrintTimeInfo(diagnosis->talon->Admission_Time);
			std::cout << " :" << std::endl;
		}
	}
	else
		std::cout << " Нет заригестрированных заболеваний " << std::endl;
}




//Привязать диагноз к пациенту
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* pacient) {
	enum Limit_Value {
		Maximum_value_for_array = 50
	};
	if (pacient->Diagnosis_point < Maximum_value_for_array) {
		pacient->Diagnosis_History[pacient->Diagnosis_point] = diagnos;
		pacient->Diagnosis_point++;
	}
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