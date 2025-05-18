
#include <iostream>
#include <string>

using namespace std;

int ReadNumber(const string & Msg)
{
	int Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

void Print(const string & text)
{
	cout << text << '\n';
}

int PowerOfN(int& N, const int & Power)
{
	int Result = N;

	for (size_t i = 1; i < Power; i++)
	{
		Result *= N;
	}
	return Result;

}

int main()
{
	int N = ReadNumber("Enter N : ");
	int Power = ReadNumber("Enter Power : ");

	Print(to_string(PowerOfN(N, Power)));
}
