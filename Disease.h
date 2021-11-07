#include <iostream>

struct Disease {
	std::string Name_Disease,
		Disease_Symptoms[50];
};

Disease GetsDiseaseData();			//Создание структуры "Заболевание"
void PutsGiseaseInfo(Disease);	//Печать структуры "Заболевание"
