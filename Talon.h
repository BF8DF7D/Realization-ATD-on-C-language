#include "Doctor.h"
#include "Time.h"
#include "Date.h"

struct Talon{
	Date Admission_Date;
	Time Admission_Time;
	int kabinet;
	Doctor* Dok;
};

Talon GetsTalonData(Doctor* );		//������� �������� ��������� "�����"
void PutsTalonInfo(Talon);	//����� ��������� "�����"