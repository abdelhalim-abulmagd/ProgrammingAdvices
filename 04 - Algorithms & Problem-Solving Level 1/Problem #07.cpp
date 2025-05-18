
#include <iostream>
#include <string>

using namespace std;

float readNumber()
{
	int number;
	
	cout << "Enter A Number : ";
	cin >> number;

	return number;
}

float getHalfNumber(const float & number)
{
	return number / 2;
}

void print(const float &number)
{
	cout << "Half Number Is : " << number << '\n';
}

int main()
{
	print(getHalfNumber(readNumber()));
}
