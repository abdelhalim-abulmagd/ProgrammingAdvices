
#include <iostream>
#include <string>

using namespace std;


struct StTriangleInfo
{
	float Hight;
	float Base;
};

StTriangleInfo ReadTriangleInfo()
{
	StTriangleInfo TriangleInfo;

	cout << "Hight : ";
	cin >> TriangleInfo.Hight;

	cout << "Base : ";
	cin >> TriangleInfo.Base;

	return TriangleInfo;
}

float CalculateTriangleArea(const StTriangleInfo &TriangleInfo)
{
	return (TriangleInfo.Base / 2) *  TriangleInfo.Hight;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateTriangleArea(ReadTriangleInfo())));
}
