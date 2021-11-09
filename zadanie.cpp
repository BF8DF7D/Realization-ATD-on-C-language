#define _CRT_SECURE_NO_WARNINGS
#include "Pacient.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <string>

int main()
{

    Disease prosrtuda, otravlenie;
    prosrtuda = GetsDiseaseData();
    std::cout << std::endl;
    otravlenie = GetsDiseaseData();
    std::cout << std::endl;
    PutsGiseaseInfo(prosrtuda);

    std::cout << std::endl << std::endl;

    Doctor unname;
    unname = GetsDoctorData();
    PutsDoctorInfo(unname);

    std::cout << std::endl << std::endl;

    Talon num;
    num = GetsTalonData(&unname);
    PutsTalonInfo(num);

    std::cout << std::endl << std::endl;

    Diagnosis one, two;
    one = GetsDiagnosisData(&num, &prosrtuda);
    two = GetsDiagnosisData(&num, &otravlenie);
    PutsDiagnosisInfo(two);

    std::cout << std::endl << std::endl;

    Pacient Bolnoi;
    Bolnoi = GetsPacientData();
    PrintPacientInfo(Bolnoi);

    GiveDiagnosisPacient(&one, &Bolnoi);
    GiveDiagnosisPacient(&two, &Bolnoi);

    std::cout << std::endl << std::endl;
    
    PrintPacientInfo(Bolnoi);

    std::string Name_Disease;
    std::cout << "Введите наименования болезни, чтобы узнать есть ли оно в истории болезни пациента" << std::endl;
    for (bool Exid_Value = false; !Exid_Value;) {
        std::cout << " Наименование : ";
        std::getline(std::cin, Name_Disease);
        if (Name_Disease.empty())
            Exid_Value = true;
        else {
            if (DiseaseOfPacient(Name_Disease, Bolnoi))
                std::cout << " В истории болезни пациента есть \"" << Name_Disease << "\"" << std::endl;
            else
                std::cout << " В истории блезни пациента не числится \"" << Name_Disease << "\"" << std::endl;
        }
    }
    _getch();
}