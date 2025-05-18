
#include <iostream>
#include <vector>

using namespace std;

vector<int> GetFibonacci(int To)
{
	int Previos = 0;
	int Current = 1;
	int Result = 0;

	vector<int> vFibonacci;

	for (size_t i = 0; i < To; i++)
	{

		Result  = Current + Previos;

		Previos = Current;
		Current = Result;

		vFibonacci.push_back(Result);
	}

	return vFibonacci;
}

void Print(vector<int> Items)
{
	for (int Item : Items)
		cout << Item << " - ";
}

int main()
{

	Print(GetFibonacci(10));
}

