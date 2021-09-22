#include"Doctor.h"

struct Talon{
	struct Admission_Date {
		int day,
			mounth,
			year;
	} Date;
	struct Admission_Time {
		int hour,
			minutes;
	} Time;
	int kabinet;
	
	Doctor* name;

};

Talon GetsTalonData();	//Функция создания структуры "Талон"