
#include <iostream>
#include <string>

using namespace std;

enum enStatus { Fail =0 , Pass = 1};

float readMark()
{
	float mark;
	
	cout << "Enter Mark : ";
	cin >> mark;

	return mark;
}

enStatus isPass(const float& mark)
{
	if(mark > 50)
		return Pass;
	return Fail;
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

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(GetResult(isPass(readMark())));
}
