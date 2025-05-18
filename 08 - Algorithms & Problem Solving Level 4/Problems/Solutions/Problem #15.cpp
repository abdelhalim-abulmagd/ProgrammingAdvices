
#include <iostream>

using namespace std;


struct StDate
{
	short Day;
	short Month;
	short Year;
};

bool IsLastMonth(int Month)
{
	return Month == 12;
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


bool IsLastDayInMonth(StDate Date)
{
	return Date.Day == DaysInMonth(Date.Month, Date.Year);
}
int main()
{
	StDate Date;

	Date.Day = 31;
	Date.Month = 12;
	Date.Year = 2022;


	cout << IsLastMonth(Date.Month) << endl;
	cout << IsLastDayInMonth(Date) << endl;

}
