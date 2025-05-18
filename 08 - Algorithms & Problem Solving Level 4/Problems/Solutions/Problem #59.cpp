
#include <iostream>

using namespace std;
enum EnCompareOptions { Before, Equal, After };


struct StDate
{
	short Day;
	short Month;
	short Year;
};

struct StPeriod
{
	StDate Start;
	StDate End;
};


void SwapTwoDate(StDate& Date1, StDate& Date2)
{
	StDate Tmp = Date1;
	Date1 = Date2;
	Date2 = Tmp;

}
bool IsDate1LessThanDate2(StDate Date1, StDate Date2)
{
	if (Date1.Year < Date2.Year)
		return true;

	else if (Date1.Year == Date2.Year)
		if (Date1.Month < Date2.Month)
			return true;

		else if (Date1.Month == Date2.Month)
			return (Date1.Day < Date2.Day);

	return false;
}

bool IsDate1EqualDate2(StDate Date1, StDate Date2)
{
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}


EnCompareOptions CompareTwoDate(StDate Date1, StDate Date2)
{
	if (IsDate1LessThanDate2(Date1, Date2))
		return Before;
	else if (IsDate1EqualDate2(Date1, Date2))
		return Equal;

	return After;
}
bool IsLeepYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
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
short DaysInYear(int Year)
{
	return IsLeepYear(Year) ? 366 : 365;
}

int GetDiffernceDaysBetweenTwoDate(StDate Date1, StDate Date2, bool IncludeLastDay = false )
{

	EnCompareOptions CompareResult = CompareTwoDate(Date1, Date2);

	if (CompareResult == After)
		SwapTwoDate(Date1, Date2);

	if (Date1.Year == Date2.Year)
		return DaysFromBiggingOfYear(Date2) - DaysFromBiggingOfYear(Date1) + IncludeLastDay;


	int Days = DaysFromBiggingOfYear(Date2) + IncludeLastDay;

	Days += (DaysInYear(Date1.Year) - DaysFromBiggingOfYear(Date1));

	for (size_t i = Date1.Year + 1; i <= Date2.Year - 1; i++)
	{
		Days += DaysInYear(i);
	}

	return CompareResult == After ? -Days : Days;
}

int main()
{
	StPeriod Period1;

	Period1.Start.Day = 1;
	Period1.Start.Month = 1;
	Period1.Start.Year = 2022;

	Period1.End.Day = 5;
	Period1.End.Month = 1;
	Period1.End.Year = 2022;


	cout << GetDiffernceDaysBetweenTwoDate(Period1.Start, Period1.End) << endl;
	cout << GetDiffernceDaysBetweenTwoDate(Period1.Start, Period1.End, true ) << endl;

}


