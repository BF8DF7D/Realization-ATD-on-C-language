#include "Talon.h"
#include "Disease.h"

//Диагноз пациента
struct Diagnosis {
	Talon* talon;		//Талон с информацией о заключении дигноза
	Disease* disease;	//Информация о диагнозе
};

Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis);		//Струкутура "Диагноз"
void PutsDiagnosisInfo(Diagnosis un);						//Печать структуры 