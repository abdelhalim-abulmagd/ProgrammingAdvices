
#include <iostream>
#include <string>

using namespace std;

enum enStatus { Fail =0 , Pass = 1};

enStatus isPass(const float& mark)
{
	if(mark > 50)
		return Pass;
	return Fail;
}


void readNumbers(float Numbers[3])
{
	for (size_t i = 0; i < 3; i++)
	{
		cout << "Enter Number "<< i+1 <<": ";
		cin >> Numbers[i];
	}
}
string GetResult(const enStatus& Status)
{
	switch (Status)
	{
	case Fail:
		return "Fail";
	case Pass:
		return "Pass";
	}
}

float SumNumbers(const float Numbers[3])
{
	return Numbers[0] + Numbers[1] + Numbers[2];
}

float GetAvrege( float  Numbers)
{
	return Numbers / 3;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	float Numbers[3];

	readNumbers(Numbers);
	print(GetResult(isPass(GetAvrege(SumNumbers(Numbers)))));
}
