
struct Doctor {
	struct FIO {
		char Last_Name[15],
			First_Name[15],
			Patronymic[15],
			Full_Name[45];
	} Fio;
	char dolgnost[20];
};

Doctor GetsDoctorData();		//Созание структуры "Доктор"
void PutsDoctorInfo(Doctor);	//Вывод структуры "Доктор"