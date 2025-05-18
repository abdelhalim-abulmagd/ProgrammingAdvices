
#include <iostream>
#include <string>

using namespace std;


struct StInfo
{
	short Digit;
	int Number;
};

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}


StInfo ReadInfo()
{
	StInfo Info;

	Info.Digit = ReadNumber("Enter A Digit : ");
	Info.Number = ReadNumber("Enter Number : ");

	return Info;
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

void Print(const string& Text)
{
	cout << Text << endl;
}
int main()
{
	StInfo Info = ReadInfo();
	Print(to_string(CountDigit(Info.Digit, Info.Number)));
}
