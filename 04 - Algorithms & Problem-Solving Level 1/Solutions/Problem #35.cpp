
#include <iostream>
#include <string>

using namespace std;

enum EnRate {Pennies = 1, Nickels = 5, Dimes = 10, Quarters = 25, Dollers = 100};
 
struct StPiggyBank
{
	short Pennies;
	short Nickels;
	short Dimes;
	short Quarters;
	short Dollers;
};


short ReadNumber(const string & Msg)
{
	short Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

StPiggyBank ReadPiggyBank()
{
	StPiggyBank PiggyBank;

	PiggyBank.Pennies =  ReadNumber("Enter Pennies : ");
	PiggyBank.Nickels =  ReadNumber("Enter Nickels : ");
	PiggyBank.Dimes =  ReadNumber("Enter Dimes : ");
	PiggyBank.Quarters =  ReadNumber("Enter Quarters : ");
	PiggyBank.Dollers =  ReadNumber("Enter Dollers : ");

	return PiggyBank;
}


int CalculatePennies(StPiggyBank &PiggyBank)
{
	return (PiggyBank.Pennies * EnRate::Pennies) + (PiggyBank.Nickels * EnRate::Nickels) + (PiggyBank.Dimes * EnRate::Dimes) + (PiggyBank.Quarters * EnRate::Quarters)  + (PiggyBank.Dollers * EnRate::Dollers) ;
}

float CalculateDollars(StPiggyBank &PiggyBank)
{
	return (float)CalculatePennies(PiggyBank) / 100;
}

void Print(const string & text)
{
	cout << text << '\n';
}


int main()
{
	StPiggyBank PiggyBank = ReadPiggyBank();

	Print(to_string(CalculatePennies(PiggyBank)));
	Print(to_string(CalculateDollars(PiggyBank)));
}
