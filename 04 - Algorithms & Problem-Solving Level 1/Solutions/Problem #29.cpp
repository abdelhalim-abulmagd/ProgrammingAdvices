
#include <iostream>
#include <string>

using namespace std;

enum EnStatus { Odd = 0 , Even = 1};

int ReadNumber()
{
	int Number;
	cout << "Enter Number";
	cin >> Number;
	return Number;
}

void Print(const string & text)
{
	cout << text << '\n';
}

EnStatus NumberType(const int & Number)
{
	if (Number % 2)
		return Even;

	return Odd;
}

int SumEvenNumbers(const int Numbers)
{
	int Result = 0;

	for (size_t i = 0; i < Numbers; i++)
	{
		if(NumberType(i) == Even)
			Result += i;
	}

	return Result ;
}

int main()
{
	Print(to_string(SumEvenNumbers(ReadNumber())));
}
