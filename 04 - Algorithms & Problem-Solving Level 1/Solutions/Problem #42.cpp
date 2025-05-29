
#include <iostream>
#include <string>

using namespace std;

struct StDurationInfo
{
	int Days;
	int Hours;
	int Minutes;
	int Seconds;
};

int MinutToSeconds()
{
	return 60;
}

int HourToSeconds()
{
	return 60 * MinutToSeconds();
}

int DayToSeconds()
{
	return 24 * HourToSeconds();
}

int DaysToSeconds(int Days)
{
	int Secondes = 0;

	for (size_t i = 0; i < Days; i++)
	{
		Secondes += DayToSeconds();
	}
	
	return Secondes;
}


int HoursToSeconds(int Hours)
{
	int Secondes = 0;

	for (size_t i = 0; i < Hours; i++)
	{
		Secondes += HourToSeconds();
	}
	
	return Secondes;
}

int MinutsToSeconds(int Minutes)
{
	int Secondes = 0;

	for (size_t i = 0; i < Minutes; i++)
	{
		Secondes += MinutToSeconds();
	}
	
	return Secondes;
}

int GetTotalSecondes(StDurationInfo DurationInfo)
{
	return DaysToSeconds(DurationInfo.Days) + HoursToSeconds(DurationInfo.Hours) + MinutsToSeconds(DurationInfo.Minutes) + DurationInfo.Seconds;
}

int ReadNumber(const string & Msg)
{
	int Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

StDurationInfo ReadDurationInfo()
{
	StDurationInfo DurationInfo;

	DurationInfo.Days = ReadNumber("Enter Days : ");
	DurationInfo.Hours = ReadNumber("Enter Hours : ");
	DurationInfo.Minutes = ReadNumber("Enter Minutes : ");
	DurationInfo.Seconds = ReadNumber("Enter Seconds : ");

	return DurationInfo;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	StDurationInfo DurationInfo = ReadDurationInfo();

	print(to_string(GetTotalSecondes(DurationInfo)));
}
