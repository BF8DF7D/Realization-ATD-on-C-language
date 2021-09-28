#include "Diagnosis.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Disease prosrtuda;
    prosrtuda = GetsDiseaseData();
    PutsGiseaseInfo(prosrtuda);

    puts("\n");

    Doctor unname;
    unname = GetsDoctorData();
    PutsDoctorInfo(unname);

    puts("\n");

    Talon num;
    num = GetsTalonData(&unname);
    PutsTalonInfo(num);

    Diagnosis diagnoz;
    diagnoz = GetsDiagnosisData(&num, &prosrtuda);
    PutsDiagnosisInfo(diagnoz);
    _getch();
}