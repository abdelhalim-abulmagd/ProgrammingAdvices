
#pragma once

#include <string>

using namespace std;

class clsDate
{
public:

	clsDate();
	clsDate(const string& Date);
	clsDate(short Day, short Month, short Year);
	virtual ~clsDate();

	static string FormatDate(clsDate Date, string Format = "dd/mm/yyyy");
	string FormatDate(string Format = "dd/mm/yyyy");

	static clsDate GetCurrentDate();

	static clsDate StringToDate(string DateString, string Separator = "/");

	static clsDate GetCurrentTime();

private:

	short Day;
	short Month;
	short Year;

};