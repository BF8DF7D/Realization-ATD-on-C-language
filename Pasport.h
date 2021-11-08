#include <iostream>

struct Pasport {
	int Series, //Cерия бланка паспорта
		Number; //Порядковый номер паспорта в серии
};
bool BoolInputPasport(Pasport*);
void SetPasportData(Pasport*);