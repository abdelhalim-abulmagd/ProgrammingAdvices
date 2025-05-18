
#include <iostream>
#include <string>

using namespace std;

void readNumbers(float Numbers[3])
{
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Enter Number "<< i+1 <<": ";
		cin >> Numbers[i];
	}
}

float SumNumbers(const float Numbers[3])
{
	return Numbers[0] + Numbers[1] + Numbers[2];
}


void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	float Numbers[3];

	readNumbers(Numbers);
	print(to_string(SumNumbers(Numbers)));
}
