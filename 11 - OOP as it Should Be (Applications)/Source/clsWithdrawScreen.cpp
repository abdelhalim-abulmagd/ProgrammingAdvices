#include "clsWithdrawScreen.h"
#include "clsInput.h"
clsWithdrawScreen::clsWithdrawScreen(){}


clsWithdrawScreen::~clsWithdrawScreen(){}


//----------------------------
// Static Public Methods
//----------------------------

void clsWithdrawScreen::Show()
{
	Header();

	if (clsClint::GetFileStatus() == clsClint::FileNotFound)
	{
		PrintStaus(clsClint::FileNotFound);
		return;
	}
	clsClint Clint = GetClint();

	Header();
	clsScreen::Line(80);
	PrintClintInfo(Clint);
	clsScreen::Line(80);

	int WithdrawAmount = clsInput::ReadNumber("Enter Withdraw Amout : ", clsInput::Positive);

	if (YesNoQuestion() == clsScreen::No)
	{
		cout << "Operation Canceld\n";
		return;
	}

	clsClint::EnStatus Status = Clint.Withdraw(WithdrawAmount);
	
	if (Status != clsClint::Success)
	{
		PrintStaus(Status);
		return;
	}

	Header();
	clsScreen::Line(80);
	PrintClintInfo(Clint);
	clsScreen::Line(80);

	PrintStaus(Status);
}

//----------------------------
// Static Private Methods
//----------------------------

void clsWithdrawScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tW I T H D R A W", 55);
}

clsClint clsWithdrawScreen::GetClint()
{
	clsClint Clint("");

	bool ClintNotFound = false;

	do
	{
		Clint = clsClint(clsInput::ReadString("Enter Account Number : "));

		ClintNotFound = (Clint.GetClintStatus() == clsClint::ClintNotFound);

		if (ClintNotFound)
			clsScreen::PrintStaus(clsClint::ClintNotFound);

	} while (ClintNotFound);

	return Clint;
}
