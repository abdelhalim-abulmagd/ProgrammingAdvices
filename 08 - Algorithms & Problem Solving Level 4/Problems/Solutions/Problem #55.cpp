
#include <iostream>

using namespace std;
enum EnDaysOfWeek { Sunday = 0, Monday = 1, Tuesday = 2, Wednesday = 3, Thursday = 4, Friday = 5, Saturday = 6 };


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

EnDaysOfWeek GetDayOrder(StDate Date)
{
	int A = (14 - Date.Month) / 12;
	int Y = Date.Year - A;
	int M = Date.Month + (12 * A) - 2;

	int D = (Date.Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12)) % 7;

	return static_cast<EnDaysOfWeek> (D);
}

bool IsWeekend(StDate Date)
{
	return GetDayOrder(Date) == Friday || GetDayOrder(Date) == Saturday;
}

StDate GetVacationReturnDate(short VacationDays, StDate VacationStartDate)
{

	for (size_t i = 0; i < VacationDays; i++)
	{
		if (IsWeekend(VacationStartDate))
			VacationDays++;
		
		VacationStartDate = AddOneDayToDate(VacationStartDate);

	}
	return VacationStartDate;
}


int main()
{
	StDate Date;

	Date.Day = 1;
	Date.Month = 1;
	Date.Year = 2022;

	Date = GetVacationReturnDate(23, Date);
	cout << Date.Day << ":" << Date.Month << ":" << Date.Year << "\n";

}
