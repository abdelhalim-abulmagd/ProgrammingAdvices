
#include <iostream>

using namespace std;

string GetDayName(short Day)
{
	string DaysOfWeek[]{ "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday" };
	return DaysOfWeek[Day];
}


short GetDayOrder(short Day, short Month, short Year)
{
	int A = (14 - Month) / 12;
	int Y = Year - A;
	int M = Month + (12 * A) - 2;

	int D = Day + Y + (Y / 4) - (Y / 100) + (Y / 400) + ((31 * M) / 12);

	return D % 7;
}

int main()
{
	short DayOrder = GetDayOrder(22,10, 2022);

	cout <<  DayOrder << endl;
	cout << GetDayName(DayOrder) << endl;
}
