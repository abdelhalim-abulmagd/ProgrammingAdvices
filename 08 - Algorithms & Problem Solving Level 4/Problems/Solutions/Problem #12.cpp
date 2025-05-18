
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

int GetDaysFromBiggingOfYear(StDate Date)
{
	int Days = 0;

	for (size_t i = 1; i <= Date.Month - 1; i++)
	{
		Days += DaysInMonth(i, Date.Year);
	}

	return (Days + Date.Day);
}

StDate DaysToDate(int Days, int Year)
{
	StDate Date;

	Date.Month = 1;
	Date.Year = Year;

	while (Days > DaysInYear(Date.Year))
	{
		Days -= DaysInYear(Date.Year);
		Date.Year++;
	}

	while (Days > DaysInMonth(Date.Month, Date.Year))
	{
		Days -= DaysInMonth(Date.Month, Date.Year);
		Date.Month++;
	}

	Date.Day = Days;

	return Date;
}

StDate AddDaysToDate(int Days, StDate Date)
{
	Days += GetDaysFromBiggingOfYear(Date);
	return DaysToDate(Days, Date.Year);
}


int main()
{
	StDate Date;

	Date.Day = 10;
	Date.Month = 10;
	Date.Year = 2022;

	Date = AddDaysToDate(2500, Date);

	cout << Date.Day << ":" << Date.Month << ":" << Date.Year;

}
