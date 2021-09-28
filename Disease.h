
struct Disease {
	char Name_Disease[20],
		Disease_Symptoms[30][50];
};

Disease GetsDiseaseData();			//Создание структуры "Заболевание"
void PutsGiseaseInfo(Disease un);	//Печать структуры "Заболевание"
