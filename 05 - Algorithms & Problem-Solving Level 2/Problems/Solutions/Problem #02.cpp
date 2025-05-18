
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

enum EnStatus { NotPrime, Prime, Odd, Even};

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

EnStatus IsEven(int Number)
{
	if ((Number % 2) == 0)
		return Even;
	return Odd;
}


EnStatus CheckPrime(int Number)
{
	int Sqrt = sqrt(Number);

	for (size_t i = 2; i <= Sqrt; i++)
	{
		if (Number % i == 0 )
			return NotPrime;
	}

	return Prime;
}

EnStatus CheckNumberType(int Number)
{
	if ( IsEven(Number) == Even && Number > 2)
		return NotPrime;

	else if (CheckPrime(Number) == NotPrime)
		return NotPrime;

	return Prime;
}

vector <int> GetPrimeNumbers(int Number)
{
	vector <int> VPrimeNumbers;

	for (size_t i = 1; i <= Number; i++)
	{
		if (CheckNumberType(i) == Prime)
			VPrimeNumbers.push_back(i);
	}
	return VPrimeNumbers;
}


void Print(vector <int> VPrimeNumbers)
{
	for (int PrimeNumber : VPrimeNumbers)
	{
		cout << PrimeNumber << endl;
	}
}

int main()
{

	Print(GetPrimeNumbers(ReadNumber("Enter N : ")));
}
