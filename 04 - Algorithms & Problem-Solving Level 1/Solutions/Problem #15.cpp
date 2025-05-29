
#include <iostream>
#include <string>

using namespace std;

struct StRectangleInfo
{
	int Hight;
	int Widgth;
};

StRectangleInfo ReadRectangleInfo()
{
	StRectangleInfo RectangleInfo;

	cout << "Hight : ";
	cin >> RectangleInfo.Hight;

	cout << "Widgth : ";
	cin >> RectangleInfo.Widgth;

	return RectangleInfo;
}

float CalculateRectangleArea(const StRectangleInfo &RectangleInfo)
{
	return RectangleInfo.Hight * RectangleInfo.Widgth;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateRectangleArea(ReadRectangleInfo())));
}
