
#include <iostream>
#include <string>

using namespace std;

struct StLoanInfo
{
	float LoanAmount;
	short Months;
};


float ReadNumber(const string& Msg )
{	
	float Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

StLoanInfo ReadLoanInfo()
{
	StLoanInfo LoanInfo;

	LoanInfo.LoanAmount = ReadNumber("Enter Loan Amount : ");
	LoanInfo.Months = ReadNumber("Enter Months : ");

	return LoanInfo;
}

float Calculat(StLoanInfo LoanInfo)
{
	return LoanInfo.LoanAmount / LoanInfo.Months;
}

void Print(const string &text)
{
	cout << text << "Monthly Amount" << '\n';
}

int main()
{
	StLoanInfo LoanInfo = ReadLoanInfo();
	
	Print(to_string(Calculat(LoanInfo)));
}
