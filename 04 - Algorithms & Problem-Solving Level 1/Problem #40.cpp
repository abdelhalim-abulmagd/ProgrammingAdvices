
#include <iostream>
#include <string>

using namespace std;

enum EnBill { Services = 10, Tax = 16 };

float ReadNumber(const string & Msg)
{
	float Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

float Calculate(float BillValu, float Percentage)
{
	return (BillValu / 100) * Percentage;
}

float GetTotalBill(float BillValu)
{
	BillValu += Calculate(BillValu, Services);
	BillValu += Calculate(BillValu, Tax);

	return BillValu;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(GetTotalBill(ReadNumber("Enter Bill Valu : "))));
}
