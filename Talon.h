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
	
	Doctor* Dok;

};

Talon GetsTalonData(Doctor* );		//������� �������� ��������� "�����"
void PutsTalonInfo(Talon);	//����� ��������� "�����"