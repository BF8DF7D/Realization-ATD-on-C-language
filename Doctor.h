#include "FIO.h"

struct Doctor {
	FIO Fio;
	std::string dolgnost;
};

Doctor GetsDoctorData();		//Созание структуры "Доктор"
void PutsDoctorInfo(Doctor);	//Вывод структуры "Доктор"