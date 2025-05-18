
#include <iostream>

using namespace std;

bool IsLeepYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

short DaysInMonth(short Month, short Year)
{
	int daysInMonth[]{ NULL, 31, NULL, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	return Month == 2 ? (IsLeepYear(Year) ? 29 : 28) : daysInMonth[Month];
}


int DaysFromTheBeggingOfYear(short Day, short Month, short Year)
{

	short Days = 0;;

	for (size_t i = 1; i <= Month - 1 ; i++)
	{
		Days +=  DaysInMonth(i, Year);
	}
	return Days + Day;
}


int main()
{

	cout << DaysFromTheBeggingOfYear(20, 9, 2022);
}
