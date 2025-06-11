#include "clsInput.h"
#include "clsTransferScreen.h"

#include <iomanip>

#include "Global.h"

//----------------------------
// Static Public Methods
//----------------------------

void clsTransferScreen::Show()
{
	Header();

	if (clsClint::GetFileStatus() == clsClint::FileNotFound)
	{
		PrintStaus(clsClint::FileNotFound);
		return;
	}
	clsClint SourceClint = GetClint("Enter Account Number To Transfer From : ");

	PrintClintInfo(SourceClint);

	clsClint TargetClint = GetClint("Enter Account Number To Transfer To : ");

	PrintClintInfo(TargetClint);

	int TransferAmount = clsInput::ReadNumber("Enter Transfer Amount : ", clsInput::Positive);

	if (YesNoQuestion() == clsScreen::No)
	{
		cout << "Operation Canceld\n";
		return;
	}

	clsClint::EnStatus Status = SourceClint.Withdraw(TransferAmount);

	if (Status != clsClint::Success)
	{
		PrintStaus(Status);
		return;
	}
	
	Status = TargetClint.Deposit(TransferAmount);

	if (Status != clsClint::Success)
	{
		PrintStaus(Status);
		return;
	}

	Header();
	PrintClintInfo(SourceClint);
	PrintClintInfo(TargetClint);

	Global::CurrentUser->SaveTransferLog(SourceClint, TargetClint, TransferAmount);

	PrintStaus(Status);
}

//----------------------------
// Static Private Methods
//----------------------------

void clsTransferScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tT R A N S F E R", 55);
}

clsClint clsTransferScreen::GetClint(string Message)
{
	clsClint Clint("");

	bool ClintNotFound = false;

	do
	{
		Clint = clsClint(clsInput::ReadString(Message));

		ClintNotFound = (Clint.GetClintStatus() == clsClint::ClintNotFound);

		if (ClintNotFound)
			clsScreen::PrintStaus(clsClint::ClintNotFound);

	} while (ClintNotFound);

	return Clint;
}

void clsTransferScreen::PrintClintInfo(clsClint Clint)
{
	clsScreen::Line(80);

	cout << left;

	cout << setw(15) << "Acount Number" << " : " << Clint.GetAcountNumber() << '\n';
	cout << setw(15) << "Name" << " : " << Clint.GetFullName() << '\n';
	cout << setw(15) << "Balance" << " : " << Clint.GetCurrentBalance() << '\n';

	clsScreen::Line(80);
}
