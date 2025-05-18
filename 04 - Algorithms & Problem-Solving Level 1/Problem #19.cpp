
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const float Pi = 3.14;
 
float ReadCircleInfo()
{
	float Diameter;
	cout << "Diameter : ";
	cin >> Diameter;
	return Diameter;
}

float CalculateCircleArea(const float &Diameter)
{
	return (Pi * pow(Diameter, 2)) / 4;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateCircleArea(ReadCircleInfo())));
}
