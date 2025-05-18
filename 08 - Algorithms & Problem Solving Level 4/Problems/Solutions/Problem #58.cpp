
#include <iostream>
enum EnCompareOptions { Before, Equal, After };

using namespace std;


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

bool IsPeriodsOverlap(StPeriod Period1, StPeriod Period2)
{
	return !(CompareTwoDate(Period1.End, Period2.Start) == Before || CompareTwoDate(Period1.Start, Period2.End) == After);
}

int main()
{
	StPeriod Period1;

	Period1.Start.Day = 1;
	Period1.Start.Month = 2;
	Period1.Start.Year = 2022;

	Period1.End.Day = 10;
	Period1.End.Month = 2;
	Period1.End.Year = 2022;

	StPeriod Period2;

	Period2.Start.Day = 11;
	Period2.Start.Month = 2;
	Period2.Start.Year = 2022;
	
	Period2.End.Day = 15;
	Period2.End.Month = 2;
	Period2.End.Year = 2022;


	cout << IsPeriodsOverlap(Period1, Period2);
}


