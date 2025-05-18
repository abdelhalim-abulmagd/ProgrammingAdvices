
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

int DaysFromBiggingOfYear(StDate Date)
{
	int Days = 0;

	for (size_t i = 1; i <= Date.Month - 1; i++)
	{
		Days += DaysInMonth(i, Date.Year);
	}

	return Days + Date.Day;
}

bool IsDate1EqualDate2(StDate Date1, StDate Date2)
{
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

int GetDiffernceDaysBetweenTwoDate(StDate Date1, StDate Date2, bool IncludeLastDay = false )
{

	if (Date1.Year == Date2.Year)
		return DaysFromBiggingOfYear(Date2) - DaysFromBiggingOfYear(Date1);


	int Days = DaysFromBiggingOfYear(Date2);
	Days += (DaysInYear(Date1.Year) - DaysFromBiggingOfYear(Date1));

	for (size_t i = Date1.Year + 1 ; i <= Date2.Year - 1; i++)
	{
		Days += DaysInYear(i);
	}

	return IncludeLastDay ? ++Days : Days;
}

int main()
{
	StDate Date;
	StDate Date2;

	Date.Day = 1;
	Date.Month = 1;
	Date.Year = 1950;

	Date2.Day = 1;
	Date2.Month = 1;
	Date2.Year = 2022;

	cout << GetDiffernceDaysBetweenTwoDate(Date, Date2) << endl;
	cout << GetDiffernceDaysBetweenTwoDate(Date, Date2, true )<< endl;

}
