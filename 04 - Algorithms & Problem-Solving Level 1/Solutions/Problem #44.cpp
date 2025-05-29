
#include <iostream>
#include <string>

using namespace std;

enum EnDaysOfWeek { WrongDay, Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday};

int ReadDay(const string & Msg)
{
	int Day;
	cout << Msg ;
	cin >> Day;
	return Day;
}

string GetDayName(EnDaysOfWeek DayOrder)
{
	switch (DayOrder)
	{
	case Sunday:
		return "Sunday";
	case Monday:
		return "Monday";
	case Tuesday:
		return "Tuesday";
	case Wednesday:
		return "Wednesday";
	case Thursday:
		return "Thursday";
	case Friday:
		return "Friday";
	case Saturday:
		return "Saturday";
	case WrongDay:
		return "Wrong Day";
	}
}

bool IsDayOrderVaild(int DayOrder)
{
	return DayOrder >= 1 && DayOrder <= 7;
}

EnDaysOfWeek GetResult(int DayOrder)
{
	if(IsDayOrderVaild(DayOrder))
		return (EnDaysOfWeek)DayOrder;
	
	return WrongDay;
}

void Print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	Print(GetDayName(GetResult(ReadDay("Enter Day : "))));
}
