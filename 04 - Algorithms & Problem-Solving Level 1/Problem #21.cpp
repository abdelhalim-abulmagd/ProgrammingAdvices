
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const float PI = 3.14;
 
float ReadCircleCircumference()
{
	float Circumference;
	cout << "Circumference : ";
	cin >> Circumference;
	return Circumference;
}

float CalculateCircleAreaByCircumference(const float &Circumference)
{
	return pow(Circumference, 2) / (4 * PI);
}	

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateCircleAreaByCircumference(ReadCircleCircumference())));
}
