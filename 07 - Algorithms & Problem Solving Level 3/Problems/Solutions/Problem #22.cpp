
#include <iostream>
#include <vector>

using namespace std;

/*
* My Sulotion
void PrintFibonacci(int To, int Counter = 0, int Result = 0, int Previos = 0, int Current = 1)
{
	if (Counter != To)
	{
		Result = Current + Previos;
		
		cout << Result << " - ";

		PrintFibonacci(To, ++Counter, Result, Current, Result);
	}
}
*/

void PrintFibonacci(int To, int Previos = 0, int Current = 1)
{
	if (To > 0)
	{
		int Result = Current + Previos;

		cout << Result << " - ";

		PrintFibonacci(--To, Current, Result);
	}
}
int main()
{

	PrintFibonacci(10);
}

