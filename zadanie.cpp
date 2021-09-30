#define _CRT_SECURE_NO_WARNINGS
#include "Pacient.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Disease prosrtuda, otravlenie;
    prosrtuda = GetsDiseaseData();
    puts("");
    otravlenie = GetsDiseaseData();
    PutsGiseaseInfo(prosrtuda);

    puts("\n");

    Doctor unname;
    unname = GetsDoctorData();
    PutsDoctorInfo(unname);

    puts("\n");

    Talon num;
    num = GetsTalonData(&unname);
    PutsTalonInfo(num);

    puts("\n");

    Diagnosis one, two;
    one = GetsDiagnosisData(&num, &prosrtuda);
    two = GetsDiagnosisData(&num, &otravlenie);
    PutsDiagnosisInfo(two);

    puts("\n");

    Pacient Bolnoi;
    Bolnoi = GetsPacientData();
    PutsPacientInfo(Bolnoi);

    GiveDiagnosisPacient(&one, &Bolnoi);
    GiveDiagnosisPacient(&two, &Bolnoi);

    puts("\n");

    char string[50];
    for (int flag = true; flag != false;) {
        scanf("%s", string);
        if (string[0] == '0')
            flag = false;
        else if (DiseaseOfPacient(string, Bolnoi))
            printf("В диагнозе пациента есть \"%s\"\n", string);
        else
            printf("В диагнозе пациента не числится \"%s\"\n", string);

    }
    _getch();
}