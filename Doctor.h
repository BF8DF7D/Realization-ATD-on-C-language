#include "FIO.h"

struct Doctor {
	FIO Fio;
	std::string dolgnost;
};

Doctor GetsDoctorData();		//������� ��������� "������"
void PutsDoctorInfo(Doctor);	//����� ��������� "������"