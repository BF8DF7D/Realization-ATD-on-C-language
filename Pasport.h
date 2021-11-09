#include <iostream>

struct Pasport {
	int Series, //Cерия бланка паспорта
		Number; //Порядковый номер паспорта в серии
};
bool BoolFormatInputPasport(Pasport*);
void SetPasportData(Pasport*);
void PrintPasportInfo(Pasport);