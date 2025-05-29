
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct StRectangleInfo
{
	int Diaganal;
	int Side;
};

StRectangleInfo ReadRectangleInfo()
{
	StRectangleInfo RectangleInfo;

	cout << "Diaganal : ";
	cin >> RectangleInfo.Diaganal;

	cout << "Side : ";
	cin >> RectangleInfo.Side;

	return RectangleInfo;
}
float CalculateRectangleArea(const StRectangleInfo &RectangleInfo)
{
	return RectangleInfo.Side *  sqrt(pow(RectangleInfo.Diaganal, 2) - pow(RectangleInfo.Side, 2));
}
void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateRectangleArea(ReadRectangleInfo())));
}
