#pragma warning(disable : 4996)

#include <iostream>
#include <ctime>

using namespace std;

enum EnDaysOfWeek { Sunday=0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6};

struct StDate
{
	short Day;
	short Month;
	short Year;
};

string GetDayShortName(short Day)
{
	string DaysOfWeek[]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DaysOfWeek[Day];
}

EnDaysOfWeek GetDayOrder(StDate Date)
{
	int A = (14 - Date.Month) / 12;
	int Y = Date.Year - A;
	int M = Date.Month + (12 * A) - 2;

	int D = (Date.Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	return static_cast<EnDaysOfWeek> (D);
}

StDate GetCurrentDate()
{
	StDate Date;

	time_t TimeNow = time(0);
	tm *LocalTime = localtime(&TimeNow);

	Date.Day = LocalTime->tm_mday;
	Date.Month = LocalTime->tm_mon + 1;
	Date.Year = LocalTime->tm_year + 1900;

	return Date;
}

void PrintDate(StDate Date)
{
	cout << "Today Is " << GetDayShortName(GetDayOrder(Date)) << " " << Date.Day << "/" << Date.Month << "/" << Date.Year << '\n';
}

bool IsEndOfWeek(StDate Date)
{
	return GetDayOrder(Date) == Saturday;
}

bool IsWeekend(StDate Date)
{
	return GetDayOrder(Date) == Friday || GetDayOrder(Date) == Saturday;
}

short DaysUntilEndOfWeek(StDate Date)
{
	return Saturday - GetDayOrder(Date);
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

short DaysUntilEndOfMonth(StDate Date)
{
	return DaysInMonth(Date.Month, Date.Year) - Date.Day + 1;
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

short DaysUntilEndOfYear(StDate Date)
{
	return DaysInYear(Date.Year) - DaysFromBiggingOfYear(Date) + 1 ;
}


int main()
{
	StDate Date = GetCurrentDate();

	Date.Day = 27;
	Date.Month = 9;
	Date.Year = 2022;

	PrintDate(Date);
	IsEndOfWeek(Date) ? cout << "Yes end of week\n" : cout << "Not end of week\n";
	IsWeekend(Date) ? cout << "Yes weekend\n" : cout << "Not weekend\n";
	IsWeekend(Date) ? cout << "No Business Day\n" : cout << "Yes Business Day\n";

	cout << "Days Until End Of Week : " << DaysUntilEndOfWeek(Date) << '\n';
	cout << "Days Until End Of Month : " << DaysUntilEndOfMonth(Date) << '\n';
	cout << "Days Until End Of Year : " << DaysUntilEndOfYear(Date) << '\n';
}