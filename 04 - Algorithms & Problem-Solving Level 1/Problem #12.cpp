
#include <iostream>
#include <string>

using namespace std;


void readNumbers(float Numbers[2])
{
	for (size_t i = 0; i < 2; i++)
	{
		cout << "Enter Number [ "<< i+1 <<" ] : ";
		cin >> Numbers[i];
	}
}

float GetMaxNumber(float Numbers[2])
{
	if(Numbers[0] > Numbers[1])
		return Numbers[0];
	return Numbers[1];
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	float Numbers[2];

	readNumbers(Numbers);
	print(to_string(GetMaxNumber(Numbers)));
}
