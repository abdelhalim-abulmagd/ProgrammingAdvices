
#include <iostream>
#include <string>

using namespace std;

enum EnMonths { WrongMonth, January, February, March, April, May, June, July, August, September, October, November, December };

int ReadMonth(const string & Msg)
{
	int Month;
	cout << Msg ;
	cin >> Month;
	return Month;
}

bool IsMonthOrderVaild(int MonthOrder)
{
	return MonthOrder >= 1 && MonthOrder <= 12;
}


EnMonths GetResult(int MonthOrder)
{
	if(IsMonthOrderVaild(MonthOrder))
		return (EnMonths)MonthOrder;
	
	return WrongMonth;
}

string GetMonthName(EnMonths Month)
{
	switch (Month)
	{
	case WrongMonth:
		return "Wrong Month";
	case January:
		return "January";
	case February:
		return "February";
	case March:
		return "March";
	case April:
		return "April";
	case May:
		return "May";
	case June:
		return "June";
	case July:
		return "July";
	case August:
		return "August";
	case September:
		return "September";
	case October:
		return "October";
	case November:
		return "November";
	case December:
		return "December";
	}
}


void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(GetMonthName(GetResult(ReadMonth("Enter Month : "))));
}
