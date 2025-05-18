
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

short GetLastDigit(int Number)
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
		RevercedNumber = RevercedNumber * 10 + GetLastDigit(Number);
		Number = RemoveLastNumber(Number);
	}

	return RevercedNumber;
}

bool IsPalindrom(int Number)
{
	return Number == ReverceNumber(Number);
}


int main()
{
	if (IsPalindrom(ReadNumber("Enter Number : ")))
		cout << "Palindrom";
	else
		cout << "Not Palindrom";

}