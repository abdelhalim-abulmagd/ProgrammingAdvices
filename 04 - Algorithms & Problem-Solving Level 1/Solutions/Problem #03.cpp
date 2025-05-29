
#include <iostream>
#include <string>

using namespace std;

enum enOddEven { odd, even};

int readNumber()
{
	int number;
	cin >> number;
	return number;
}

bool isEven(int num)
{
	return num % 2;
}

string result (int num)
{
	if (isEven(num))
	{
		return "Even";
	}
	else
	{
		return "Odd";
	}
}


void print()
{
	cout << result(readNumber()) << '\n';
}

int main()
{
	print();

}
