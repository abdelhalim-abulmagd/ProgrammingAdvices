
#include <iostream>
#include <string>

using namespace std;


int ReadHours(const string & Msg)
{
	int Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

float GetDays(int Hours)
{
	return Hours / 24;
}

float GetWeeks(int Days)
{
	return Days / 7;
}

void Print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	int Hours = ReadHours("Enter Number Of Hours : ");
	float Days = GetDays(Hours);
	float Weeks = GetWeeks(Days);
	
	Print(to_string(Days));
	Print(to_string(Weeks));
}
