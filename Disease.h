#include <iostream>

struct Disease {
	std::string Name_Disease,
		Disease_Symptoms[50];
};

Disease GetsDiseaseData();			//�������� ��������� "�����������"
void PutsGiseaseInfo(Disease);	//������ ��������� "�����������"
