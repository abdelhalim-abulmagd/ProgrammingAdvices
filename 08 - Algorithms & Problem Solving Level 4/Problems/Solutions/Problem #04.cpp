
#include <iostream>

using namespace std;


bool IsLeepYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}


short DaysInYear(int Year)
{
	return IsLeepYear(Year) ? 366 : 365;
}


short HoursInYear(int Year)
{
	return DaysInYear(Year) * 24;
}

int MinutesInYear(int Year)
{
	return HoursInYear(Year) * 60;
}
int SecondsInYear(int Year)
{
	return MinutesInYear(Year) * 60;
}

int main()
{
	cout << DaysInYear(2000) << endl;
	cout << HoursInYear(2000) << endl;
	cout << MinutesInYear(2000) << endl;
	cout << SecondsInYear(2000) << endl;
}
