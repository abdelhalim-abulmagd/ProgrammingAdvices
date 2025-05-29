
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

enum EnNumberType { Prime, NotPrime }; 

int ReadNumber(const string & Msg)
{
	int Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

bool IsValid(int Number1, int Number2)
{
	if((Number1 % Number2) == 0)
		return true;
	return false;
}

EnNumberType CheckNumberType(int Number)
{
	int SqrtNumber = sqrt(Number);

	for (size_t i = 2; i <= SqrtNumber; i++)
	{
		if (IsValid(Number, i))
			return NotPrime;
	}
	
	return Prime;
}

string GetResult(EnNumberType NumberType)
{
	switch (NumberType)
	{
	case Prime:
		return "Prime";
	
	case NotPrime:
		return "Not Prime";
	}
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(GetResult(CheckNumberType(ReadNumber("Enter Number : "))));
}
