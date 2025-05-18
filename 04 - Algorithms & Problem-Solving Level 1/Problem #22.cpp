
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const float PI = 3.14;

struct StTriangleInfo
{
	float Side;
	float Base;
};

StTriangleInfo ReadTriangleInfo()
{
	StTriangleInfo TriangleInfo;
	cout << "Side : ";
	cin >> TriangleInfo.Side;

	cout << "Base : ";
	cin >> TriangleInfo.Base;

	return TriangleInfo;
}

float CalculateCircleAreaByIsoscelesTriangle(const StTriangleInfo &TriangleInfo)
{
	return PI * (pow(TriangleInfo.Base, 2) / 4) * ((2* TriangleInfo.Side - TriangleInfo.Base)  / (2* TriangleInfo.Side + TriangleInfo.Base) );
}	

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateCircleAreaByIsoscelesTriangle(ReadTriangleInfo())));
}
