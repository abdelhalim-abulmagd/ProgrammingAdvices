
#include <iostream>
#include <iomanip>

using namespace std;


string GetMonthShortName(short Month)
{
	string MonthsOfYear[] {"", "Jan", "Feb", "Mar", "Apr", "May", "Jun",
	"Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

	return MonthsOfYear[Month];
}

string GetDayShortName(short Day)
{
	string DaysOfWeek[]{ "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
	return DaysOfWeek[Day];
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

short GetDayOrder(short Day, short Month, short Year)
{
	int A = (14 - Month) / 12;
	int Y = Year - A;
	int M = Month + (12 * A) - 2;

	int D = Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12);

	return D % 7;
}

void PrintCalenderHeader(short Month)
{
	cout << "---------------" << GetMonthShortName(Month) << "---------------\n";

	for (size_t i = 0; i < 7; i++)
		cout << left << setw(5) << GetDayShortName(i);

	cout << '\n';

}

short PrintSpacesAfterPrintDays(short Month, short Year)
{
	short i = 0;

	for (i = 0; i < GetDayOrder(1, Month, Year); i++)
		cout << setw(5) << " ";

	return i;
}

void PrintCalenderDays(short Month, short Year)
{

	short NextDay = PrintSpacesAfterPrintDays(Month, Year);

	for (size_t Day = 1; Day <= DaysInMonth(Month, Year); Day++)
	{
		if (++NextDay > 7)
		{
			cout << '\n';
			NextDay = 1;
		}
		cout << setw(5) << Day;
	}
}

void PrintCalender(short Month, short Year)
{
	PrintCalenderHeader(Month);
	PrintCalenderDays(Month, Year);
	cout << "\n---------------------------------\n";

}




int main()
{
	PrintCalender(10, 2030);
}
