
#include <iostream>

using namespace std;

enum EnCompareOptions{Before, Equal, After};

struct StDate
{
	short Day;
	short Month;
	short Year;
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

int main()
{
	StDate Date;
	StDate Date2;

	Date.Day = 1;
	Date.Month = 1;
	Date.Year = 2022;

	Date2.Day = 1;
	Date2.Month = 1;
	Date2.Year = 2022;

	cout << CompareTwoDate(Date, Date2);
}


