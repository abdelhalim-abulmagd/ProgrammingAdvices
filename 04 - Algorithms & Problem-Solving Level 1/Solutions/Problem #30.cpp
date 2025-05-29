
#include <iostream>
#include <string>

using namespace std;

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

int FactorialNumber(int N)
{
	int Result = 1;

	for (size_t i = N; i > 0; i--)
	{
		Result *= i ;
	}
	return Result;
}

int main()
{
	Print(to_string(FactorialNumber(ReadNumber())));
}
