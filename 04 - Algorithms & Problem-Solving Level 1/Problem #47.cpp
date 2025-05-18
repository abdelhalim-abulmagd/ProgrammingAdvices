
#include <iostream>
#include <string>

using namespace std;

struct StLoanInfo
{
	float LoanAmount;
	float MonthlyPayment;
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
	LoanInfo.MonthlyPayment = ReadNumber("Enter Monthly Amount : ");

	return LoanInfo;
}

float Calculat(StLoanInfo LoanInfo)
{
	return LoanInfo.LoanAmount / LoanInfo.MonthlyPayment;
}

void Print(const string &text)
{
	cout << text << "Months" << '\n';
}

int main()
{
	StLoanInfo LoanInfo = ReadLoanInfo();
	
	Print(to_string(Calculat(LoanInfo)));
}
