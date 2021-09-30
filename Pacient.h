#include "Diagnosis.h"

struct Pacient {
	//Юридические данные
	struct Legal_Data {
		//ФИО пациента
		struct FIO {
			char Last_Name[15], //Фамилия
				First_Name[15], //Имя
				Patronymic[15], //Отчество
				Full_Name[45];
		} Fio;

		//Дата рождения
		struct DATA_BRITH {
			int day, //День
				mounth, //Месяц
				year; //Год
		} Data_Brith;

		//Паспотрные данные
		struct PASPORT {
			char Series[5], //Cерия бланка паспорта
				Number[7]; //Порядковый номер паспорта в серии
		} Pasport;

		char Medical_Card[8]; //Номер медицинской карты

	} Legal;

	Diagnosis* Diagn[30];
	int Diagnosis_point;
};

Pacient GetsPacientData();										//Создание структуры
void PutsPacientInfo(Pacient);									//Печать информации о пациенте
void GiveDiagnosisPacient(Diagnosis* diagnos, Pacient* un);		//Связь дигноза с пациентом 
bool DiseaseOfPacient(char disease[], Pacient un);				//Переносил ли пациент данное заболевание.