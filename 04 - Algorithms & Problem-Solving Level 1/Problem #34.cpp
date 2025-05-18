
#include <iostream>
#include <string>

using namespace std;

enum EnPercentage { Zero , One , Two, Three, Five};

float ReadTotalSales(const string & Msg)
{
	float Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

void Print(const string & text)
{
	cout << text << '\n';
}

bool CheckTotalSalesBetweenTwoNumbers(const float & TotalSales, const int&  From,const int & To)
{
	return TotalSales >= From && TotalSales <= To;
}

EnPercentage GetPercentage(const float & TotalSales)
{
	if(CheckTotalSalesBetweenTwoNumbers(TotalSales, 1000000, 1000000000))
		return One;

	else if(CheckTotalSalesBetweenTwoNumbers(TotalSales, 500000, 1000000))
		return Two;

	else if(CheckTotalSalesBetweenTwoNumbers(TotalSales, 100000, 500000))
		return Three;

	else if(CheckTotalSalesBetweenTwoNumbers(TotalSales, 50000, 100000))
		return Five;

	else
		return Zero;
}

float Calculate(short Percentage, float TotalSales)
{
	return (TotalSales / 100 ) * Percentage;
}

int GetResult(const EnPercentage& Percentage, float TotalSales)
{
	switch (Percentage)
	{
	case One:
		return Calculate(1, TotalSales);
	case Two:
		return Calculate(2, TotalSales);
	case Three:
		return Calculate(3, TotalSales);
	case Five:
		return Calculate(5, TotalSales);
	case Zero:
		return Calculate(0, TotalSales);
	}
}

int main()
{
	int TotalSales = ReadTotalSales("Total Sales : ");

	Print(to_string(GetResult(GetPercentage(TotalSales), TotalSales)));
}
