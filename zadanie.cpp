#include "Talon.h"
#include <locale.h>
#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Doctor name;
    name = GetsDoctorData();
    PutsDoctorInfo(name);
    
    puts("");
    
    Talon num;
    num = GetsTalonData(&name);
    PutsTalonInfo(num);
    
}