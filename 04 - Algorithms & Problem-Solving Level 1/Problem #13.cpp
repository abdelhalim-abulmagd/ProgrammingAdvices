
#include <iostream>
#include <string>

using namespace std;


void readNumbers(float Numbers[3])
{
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Enter Number [ "<< i+1 <<" ] : ";
		cin >> Numbers[i];
	}
}

float GetMaxNumber(float Numbers[3])
{
	if(Numbers[0] > Numbers[1] && Numbers[0] > Numbers[2] )
		return Numbers[0];

	if(Numbers[1] > Numbers[2])
		return Numbers[1];

	return Numbers[2];
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	float Numbers[3];

	readNumbers(Numbers);
	print(to_string(GetMaxNumber(Numbers)));
}
