
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const float Pi = 3.14;

float ReadCircleInfo()
{
	float Radios;
	cout << "Radios : ";
	cin >> Radios;
	return Radios;
}

float CalculateCircleArea(const float &Radios)
{
	return Pi * pow(Radios, 2);
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateCircleArea(ReadCircleInfo())));
}
