#include "Talon.h"
#include "Disease.h"

//������� ��������
struct Diagnosis {
	Talon* talon;		//����� � ����������� � ���������� �������
	Disease* disease;	//���������� � ��������
};

Diagnosis GetsDiagnosisData(Talon* Dok, Disease* Dis);		//���������� "�������"
void PutsDiagnosisInfo(Diagnosis un);						//������ ��������� 