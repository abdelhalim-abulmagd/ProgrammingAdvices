
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

int GetDaysFromBiggingOfYear(StDate Date)
{
	int Days = 0;

	for (size_t i = 1; i <= Date.Month - 1; i++)
	{
		Days += DaysInMonth(i, Date.Year);
	}

	return (Days + Date.Day);
}

short DaysInYear(int Year)
{
	return IsLeepYear(Year) ? 366 : 365;
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

StDate AddOneDayToDate(StDate Date)
{
	if (IsLastDayInMonth(Date))
	{
		if (IsLastMonth(Date.Month))
		{
			Date.Day = 1;
			Date.Month = 1;
			Date.Year++;
		}
		else
		{
			Date.Month++;
			Date.Day = 1;
		}
	}
	else
		Date.Day++;

	return Date;
}


StDate AddOneMonthToDate(StDate Date)
{

	if (IsLastMonth(Date.Month))
	{
		Date.Month = 1;
		Date.Year++;
	}
	else
		Date.Month++;

	Date.Day = Date.Day > DaysInMonth(Date.Month, Date.Year) ? DaysInMonth(Date.Month, Date.Year) : Date.Day;

	return Date;
}

StDate AddMonthsToDate(int Months, StDate Date)
{
	for (size_t i = 0; i < Months; i++)
	{
		Date = AddOneMonthToDate(Date);
	}

	return Date;
}


StDate AddOneYearToDate(StDate Date)
{
	Date.Year++;

	Date.Day = Date.Day > DaysInMonth(Date.Month, Date.Year) ? DaysInMonth(Date.Month, Date.Year) : Date.Day;

	return Date;
}

StDate AddYearsToDate(int Years , StDate Date)
{
	for (size_t i = 0; i < Years; i++)
	{
		Date = AddOneYearToDate(Date);
	}

	return Date;
}

int main()
{
	StDate Date;

	Date.Day = 1;
	Date.Month = 1;
	Date.Year = 2000;

	Date = AddOneDayToDate(Date);
	cout << "1- 1 Day : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddDaysToDate(10, Date);
	cout << "2- 10 Day : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddDaysToDate(7, Date);
	cout << "3- 1 Week : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddDaysToDate((7 * 10), Date);
	cout << "4- 10 Weeks : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddOneMonthToDate(Date);
	cout << "5- 1 Month : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddMonthsToDate(5, Date);
	cout << "6- 5 Month : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddOneYearToDate(Date);
	cout << "7- 1 Year : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddYearsToDate(10, Date);
	cout << "8- 10 Year : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddYearsToDate(10, Date);
	cout << "9- 10 Year : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddYearsToDate(10, Date);
	cout << "10- 1 Decade : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;
	
	Date = AddYearsToDate(10*10, Date);
	cout << "11- 10 Decades : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddYearsToDate(10 * 10, Date);
	cout << "12- 10 Decades : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddYearsToDate(100, Date);
	cout << "13- 1 Century : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = AddYearsToDate(1000, Date);
	cout << "14- 1 Millennium : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

}