
#include <iostream>

using namespace std;


struct StDate
{
	short Day;
	short Month;
	short Year;
};


bool IsLeepYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short DaysInMonth(short Month, short Year)
{
	int daysInMonth[]{ NULL, 31, NULL, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return Month == 2 ? (IsLeepYear(Year) ? 29 : 28) : daysInMonth[Month];
}

bool IsValidMonth(short Month)
{
	return Month >= 1 && Month <= 12;
}


bool IsValidDate(StDate Date)
{
	if (!IsValidMonth(Date.Month))
		return false;

	return Date.Day >= 1 && Date.Day <= DaysInMonth(Date.Month, Date.Year);
}

int main()
{
	StDate Date;

	Date.Day = 31;
	Date.Month = 4;
	Date.Year = 2022;



	cout << IsValidDate(Date) << endl;

}


