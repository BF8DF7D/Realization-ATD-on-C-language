#include "Talon.h"
#include "Disease.h"

//������� ��������
struct Diagnosis {
	Talon* Tal;		//����� � ����������� � ���������� �������
	Disease* Dis;	//���������� � ��������
};

Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis);		//���������� "�������"
void PutsDiagnosisInfo(Diagnosis un);						//������ ��������� 