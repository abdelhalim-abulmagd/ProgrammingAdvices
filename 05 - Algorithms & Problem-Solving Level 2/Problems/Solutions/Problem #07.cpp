
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

int ReverceNumber(int Number)
{
	int RevercedNumber = 0;

	while (Number)
	{
		RevercedNumber = RevercedNumber * 10 + GetLastNumber(Number);
		Number = RemoveLastNumber(Number);
	}

	return RevercedNumber;
}

void Print(const string& Text)
{
	cout << Text << endl;
}
int main()
{
	int Number = ReadNumber("Enter Number : ");
	Print(to_string(ReverceNumber(Number)));
}
