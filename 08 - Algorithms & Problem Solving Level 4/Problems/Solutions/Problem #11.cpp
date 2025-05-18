
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


short DaysInYear(int Year)
{
	return IsLeepYear(Year) ? 366 : 365;
}


short DaysInMonth(short Month, short Year)
{
	int daysInMonth[]{ NULL, 31, NULL, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return Month == 2 ? (IsLeepYear(Year) ? 29 : 28) : daysInMonth[Month];
}


StDate DaysToDate(int Days, short Year)
{
	StDate Date;

	Date.Month = 1;
	Date.Year = Year;

	while (DaysInYear(Date.Year) < Days)
	{
		Days -= DaysInYear(Date.Year);
		Date.Year++;
	}
	
	while (DaysInMonth(Date.Month, Year) < Days)
	{	
		Days -= DaysInMonth(Date.Month, Year);
		Date.Month++;
	}

	Date.Day= Days;
	return Date;
}


int main()
{

	cout << DaysToDate(263, 2022).Day << ":" << DaysToDate(263, 2022).Month << ":" << DaysToDate(263, 2022).Year;
}
