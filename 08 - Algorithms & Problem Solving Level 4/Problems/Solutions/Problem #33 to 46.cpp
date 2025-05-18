
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

StDate DecreaseDateByOneDay(StDate Date)
{
	if (Date.Day == 1)
	{
		if (Date.Month == 1)
		{
			Date.Month = 12;
			Date.Year--;
		}
		else
		{
			Date.Month--;
		}
		Date.Day = DaysInMonth(Date.Month, Date.Year);
	}
	else
		Date.Day--;

	return Date;
}

StDate DecreaseDateByXDay(int Days, StDate Date)
{
	for (size_t i = 0; i < Days; i++)
	{
		Date = DecreaseDateByOneDay(Date);
	}

	return Date;
}


StDate DecreaseDateByOneMonth(StDate Date)
{
	if (Date.Month == 1)
	{
		Date.Month = 12;
		Date.Year--;
	}
	else
	{
		Date.Month--;
	}

	Date.Day = Date.Day > DaysInMonth(Date.Month, Date.Year) ? DaysInMonth(Date.Month, Date.Year) : Date.Day;

	return Date;

}
StDate DecreaseDateByXMonth(int Months, StDate Date)
{
	for (size_t i = 0; i < Months; i++)
	{
		Date = DecreaseDateByOneMonth(Date);
	}
	return Date;
}


StDate DecreaseDateByXYears(int Years, StDate Date)
{
	Date.Year -= Years;
	Date.Day = Date.Day > DaysInMonth(Date.Month, Date.Year) ? DaysInMonth(Date.Month, Date.Year) : Date.Day;
	return Date;
}

int main()
{
	StDate Date;

	Date.Day = 1;
	Date.Month = 1;
	Date.Year = 2023;

	Date = DecreaseDateByOneDay(Date);
	cout << "1- Subtruct 1 Day : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXDay(10, Date);
	cout << "2- Subtruct 10 Day : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXDay(7, Date);
	cout << "3- Subtruct 1 Week : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXDay((7 * 10), Date);
	cout << "4-  Subtruct 10 Weeks : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;
	
	Date = DecreaseDateByOneMonth(Date);
	cout << "5-  Subtruct 1 Month : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXMonth(5, Date);
	cout << "6- Subtruct  5 Month : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(1, Date);
	cout << "7- Subtruct  1 Year : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(10, Date);
	cout << "8-  Subtruct 10 Year : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(10, Date);
	cout << "9- Subtruct  10 Year : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(10, Date);
	cout << "10-  Subtruct 1 Decade : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;
	
	Date = DecreaseDateByXYears(10*10, Date);
	cout << "11- Subtruct  10 Decades : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(10 * 10, Date);
	cout << "12- Subtruct  10 Decades : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(100, Date);
	cout << "13- Subtruct  1 Century : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;

	Date = DecreaseDateByXYears(1000, Date);
	cout << "14- Subtruct  1 Millennium : " << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;
}