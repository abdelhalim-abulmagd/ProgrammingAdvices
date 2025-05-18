
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum EnStatus { NotPerfectNumber, PerfectNumber, Odd, Even };

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

EnStatus CheckNumberType(int Number, int Mod = 2)
{
	return (Number % Mod == 0) ? Even : Odd;
}

EnStatus CheckPerfectNumber(int Number)
{
	int ResultSum = 0;

	for (size_t i = 1; i < Number; i++)
	{
		if (CheckNumberType(Number, i) == Even)
			ResultSum += i;
	}

	return (ResultSum == Number) ? PerfectNumber : NotPerfectNumber;
}

vector <int> GetPerfectnumbers(int N)
{
	vector <int> PerfectNumbers;

	for (size_t i = 1; i <= N; i++)
	{
		if (CheckPerfectNumber(i) == PerfectNumber)
			PerfectNumbers.push_back(i);
	}

	return PerfectNumbers;
}

void PrintVector(vector <int> PerfectNumbers)
{
	for (int PerfectNumber : PerfectNumbers)
		cout << PerfectNumber << endl;
}

int main()
{
	int N = ReadNumber("Enter Number : ");
	vector <int> PerfectNumbers = GetPerfectnumbers(N);
	PrintVector(PerfectNumbers);
}
