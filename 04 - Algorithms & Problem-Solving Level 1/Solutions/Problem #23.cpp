
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const float PI = 3.14;

struct StTriangleInfo
{
	float Side1, Side2, Side3;
};

StTriangleInfo ReadTriangleInfo()
{
	StTriangleInfo TriangleInfo;
	cout << "Side [1] : ";
	cin >> TriangleInfo.Side1;

	cout << "Side [2] : ";
	cin >> TriangleInfo.Side2;

	cout << "Side [3] : ";
	cin >> TriangleInfo.Side3;

	return TriangleInfo;
}

float CalculateCircleAreaByArbitraryTriangle(const StTriangleInfo &TriangleInfo)
{
	float P = (TriangleInfo.Side1 +  TriangleInfo.Side2 +  TriangleInfo.Side3) / 2;

	float Numerator = TriangleInfo.Side1 * TriangleInfo.Side2 *  TriangleInfo.Side3 ;
	float Denamerator = 4 * sqrt(P * (P - TriangleInfo.Side1) * (P - TriangleInfo.Side2) * (P - TriangleInfo.Side3) ) ;

	float Area = PI * pow(Numerator / Denamerator, 2);

	return Area;
}	

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateCircleAreaByArbitraryTriangle(ReadTriangleInfo())));
}
