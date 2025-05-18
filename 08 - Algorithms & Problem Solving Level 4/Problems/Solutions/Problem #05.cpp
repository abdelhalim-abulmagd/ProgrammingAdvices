
#include <iostream>

using namespace std;



bool IsLeepYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}


short DaysInMonth(short Month, short Year)
{
	int daysInMonth[] { NULL, 31, NULL, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return Month == 2 ? (IsLeepYear(Year) ? 29 : 28) : daysInMonth[Month];
}


short HoursInMonth(short Month, short Year)
{
	return DaysInMonth(Month, Year) * 24;
}

int MinutesInMonth(short Month, short Year)
{
	return HoursInMonth(Month, Year) * 60;
}
int SecondsInMonth(short Month, short Year)
{
	return MinutesInMonth(Month, Year) * 60;
}

int main()
{
	cout << DaysInMonth(2, 2000) << endl;
	cout << HoursInMonth(2, 2000) << endl;
	cout << MinutesInMonth(2, 2000) << endl;
	cout << SecondsInMonth(2, 2000) << endl;
}
