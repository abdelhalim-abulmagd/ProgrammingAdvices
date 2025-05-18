
#include <iostream>
#include <string>
#include <vector>

using namespace std;


struct StDigitInfo
{
	short Digit = 0;
	short Count = 0;
};

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}



short GetLastNumber(int Number)
{
	return Number % 10;
}

int RemoveLastNumber(int Number)
{
	return Number / 10;
}

int CountDigit(short Digit, int Number)
{
	int Counter = 0;

	while (Number)
	{
		if (GetLastNumber(Number) == Digit)
			Counter++;

		Number = RemoveLastNumber(Number);
	}

	return Counter;
}

bool IsExist(short Digit, vector <StDigitInfo> DigitsInfo)
{
	for (size_t i = 0; i < DigitsInfo.size(); i++)
	{
		if (DigitsInfo[i].Digit == Digit)
			return true;
	}

	return false;
}

vector <StDigitInfo> GetDigits(int Number)
{
	vector <StDigitInfo> DigitsInfo;

	while (Number)
	{
		short Digit = GetLastNumber(Number);
		Number = RemoveLastNumber(Number);

		if (IsExist(Digit, DigitsInfo))
			continue;

		StDigitInfo DigitInfo;
		DigitInfo.Digit = Digit;

		DigitsInfo.push_back(DigitInfo);
	}

	return DigitsInfo;
}


vector <StDigitInfo> CountNumbers(vector <StDigitInfo> DigitsInfo, int Number)
{
	for (size_t i = 0; i < DigitsInfo.size(); i++)
	{
		DigitsInfo[i].Count = CountDigit(DigitsInfo[i].Digit, Number);
	}

	return DigitsInfo;
}

void Print(vector <StDigitInfo> DigitsInfo)
{
	for (size_t i = 0; i < DigitsInfo.size(); i++)
	{
		cout << DigitsInfo[i].Digit << " - " << DigitsInfo[i].Count << endl;
	}
}

int main()
{
	int Number = ReadNumber("Enter Number : ");
	vector <StDigitInfo> DigitsInfo = GetDigits(Number);

	DigitsInfo = CountNumbers(DigitsInfo, Number);

	Print(DigitsInfo);
}
