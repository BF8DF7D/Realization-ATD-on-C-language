
struct Doctor {
	struct FIO {
		char Last_Name[15],
			First_Name[15],
			Patronymic[15];
	} Fio;
	char dolgnost[20];
};

Doctor GetsDoctorData();		//������� ��������� "������"
void PutsDoctorInfo(Doctor);	//����� ��������� "������"