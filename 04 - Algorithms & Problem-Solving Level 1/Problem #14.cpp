
#include <iostream>
#include <string>

using namespace std;

void ReadTwoNumbers( int& num1,  int &num2)
{
	cout << "Num 1 : ";
	cin >> num1;

	cout << "Num 2 : ";
	cin >> num2;
}

void SwapTwoNumbers( int& num1,  int &num2)
{
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
}

void print(const string &text1, const string &text2="")
{
	cout << text1 << '\n';
	cout << text2 << '\n';
}

int main()
{
	int num1, num2;

	ReadTwoNumbers(num1, num2);
	SwapTwoNumbers(num1, num2);

	print(to_string(num1), to_string(num2));
}
