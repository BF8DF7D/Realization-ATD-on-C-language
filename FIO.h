#include <iostream>

struct FIO {
	std::string Last_Name,
		First_Name,
		Patronymic,
		Full_Name;
};

bool BoolFormatInputFIO(FIO*);
void SetFIOData(FIO*);