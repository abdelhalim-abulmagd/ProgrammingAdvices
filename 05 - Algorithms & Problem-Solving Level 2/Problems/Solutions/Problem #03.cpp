
#include <iostream>
#include <string>

using namespace std;

enum EnStatus { NotPerfectNumber, PerfectNumber, Odd, Even };

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

EnStatus CheckNumberType(int Number, int Mod = 2)
{
	if (Number % Mod == 0)
		return Even;

	return Odd;
}

EnStatus CheckPerfectNumber(int Number)
{
	int ResultSum = 0;

	for (size_t i = 1; i < Number; i++)
	{
		if (CheckNumberType(Number, i) == Even)
			ResultSum += i;

		if (ResultSum > Number)
			return NotPerfectNumber;
	}

	return PerfectNumber;
}

string GetResult(EnStatus Status)
{
	switch (Status)
	{

	case NotPerfectNumber:
		return "Not Perfect Number";

	case PerfectNumber:
		return "Perfect Number";
	}
}

void Print(const string & Text)
{
	cout << Text << endl;
}

int main()
{
	Print(GetResult(CheckPerfectNumber(ReadNumber("Enter Number : "))));
}
