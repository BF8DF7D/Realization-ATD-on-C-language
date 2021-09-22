
struct Disease {
	char Name_Disease[20],
		*Disease_Symptoms = (char*)malloc(sizeof(char)),
		*Symtoms_pointer = (char*)malloc(sizeof(char));
};

Disease GetsDiseaseData();	//Функция создания структуры "Заболевание"
