
#include <iostream>
#include <string>

using namespace std;

enum EnInfo { SecondsInDay = 86400, SecondsInHour = 3600, SecondsInMinut = 60 };

struct StResult
{
	int Days;
	int Hours;
	int Minutes;
	int Seconds;
};


int ReadNumbersOfSeconds(const string & Msg)
{
	int NumbersOfSeconds;
	cout << Msg ;
	cin >> NumbersOfSeconds;
	return NumbersOfSeconds;
}

int SecondsToDays(int Seconds)
{
	return Seconds / SecondsInDay;
}

int SecondsToHours(int Seconds)
{
	return Seconds / SecondsInHour;
}

int SecondsToMinuts(int Seconds)
{
	return Seconds / SecondsInMinut;
}

int GetRemainder(int Seconds, EnInfo Info)
{
	return  Seconds  % Info;
}

StResult GetResult(int Seconds)
{
	StResult Result;

	Result.Days = SecondsToDays(Seconds);
	Seconds = GetRemainder(Seconds, SecondsInDay);

	Result.Hours = SecondsToHours(Seconds);
	Seconds = GetRemainder(Seconds, SecondsInHour);
	
	Result.Minutes = SecondsToMinuts(Seconds);

	Result.Seconds = GetRemainder(Seconds, SecondsInMinut);

	return Result;
}

string FormatResult(StResult Result)
{
	return to_string(Result.Days) + ":" + to_string(Result.Hours) + ":" + to_string(Result.Minutes) + ":" + to_string(Result.Seconds);
}

void Print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	int Seconds = ReadNumbersOfSeconds("Enter Number Of Seconds : ");

	Print(FormatResult(GetResult(Seconds)));
}




