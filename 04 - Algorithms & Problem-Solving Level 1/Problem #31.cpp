
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
	int N = ReadNumber();

	Print(to_string(PowerOfN(N, 2)));
	Print(to_string(PowerOfN(N, 3)));
	Print(to_string(PowerOfN(N, 4)));
}
