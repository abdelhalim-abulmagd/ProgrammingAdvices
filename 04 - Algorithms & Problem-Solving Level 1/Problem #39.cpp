
#include <iostream>
#include <string>

using namespace std;

struct StBillInfo
{
	float TotalBill;
	float CashPaid;
};

float ReadNumber(const string & Msg)
{
	float Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

StBillInfo ReadBillInfo()
{
	StBillInfo BillInfo;

	BillInfo.TotalBill =  ReadNumber("Enter Total Bill : ");
	BillInfo.CashPaid =  ReadNumber("Enter Cash Paid : ");

	return BillInfo;
}

float Subtract(int Number1, int Number2)
{
	return  Number1 - Number2;
}

float CalculateRemainder(StBillInfo BillInfo )
{
	return Subtract(BillInfo.TotalBill, BillInfo.CashPaid);
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(CalculateRemainder(ReadBillInfo())));
}
