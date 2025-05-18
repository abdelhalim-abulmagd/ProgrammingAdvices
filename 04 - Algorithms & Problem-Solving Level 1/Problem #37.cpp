
#include <iostream>
#include <string>

using namespace std;

float ReadNumber(const string & Msg)
{
	float Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

bool IsValid(const int &Number)
{
	return Number != -99;
}

float SumNumbers()
{
	float Number = 0;
	float Result = 0;
	
	while (IsValid(Number))
	{
		Result += Number;
		Number = ReadNumber("Enter Number : ");
	}
	
	return Result;
	
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(SumNumbers()));
}
