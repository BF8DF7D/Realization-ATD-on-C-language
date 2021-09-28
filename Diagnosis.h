#include "Talon.h"
#include "Disease.h"

//Диагноз пациента
struct Diagnosis {
	Talon* Dok;		//Талон с информацией о заключении дигноза
	Disease* Dis;	//Информация о диагнозе
};