
#include <iostream>
#include <string>

using namespace std;

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

int SumNumber(int Number)
{
	int ResultSum = 0;

	while(Number)
	{
		ResultSum += GetLastNumber(Number);
		Number = RemoveLastNumber(Number);
	}

	return ResultSum;
}

void Print(const string& Text)
{
	cout << Text << endl;
}
int main()
{
	int Number = ReadNumber("Enter Number : ");

	Print(to_string(SumNumber(Number)));
}
