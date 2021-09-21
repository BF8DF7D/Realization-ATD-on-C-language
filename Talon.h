#include"Doctor.h"

struct {
	struct Admission_Date {
		int day,
			mounth,
			year;
	} Date;
	struct Admission_Time {
		int hour,
			minutes;
	} Time;
	int kabinet;
	
	Doctor* name;

};