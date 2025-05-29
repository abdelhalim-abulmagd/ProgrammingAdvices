
#include <iostream>
#include <string>

using namespace std;


int ReadNumber()
{
	int Number;
	cout << "Enter Number";
	cin >> Number;
	return Number;
}

void print(const string & text)
{
	cout << text << '\n';
}


void PrintNumbers(const int Numbers)
{
	for (size_t i = 1; i <= Numbers; i++)
	{
		print(to_string(i));
	}
}


int main()
{
	PrintNumbers(ReadNumber());
}
