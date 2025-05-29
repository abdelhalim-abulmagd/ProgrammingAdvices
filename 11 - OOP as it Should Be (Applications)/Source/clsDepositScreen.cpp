#include "clsDepositScreen.h"
#include "clsInput.h"

clsDepositScreen::clsDepositScreen() {}

clsDepositScreen::~clsDepositScreen() {}

//----------------------------
// Static Public Methods
//----------------------------
void clsDepositScreen::Show()
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

	int DepositAmount = clsInput::ReadNumber("Enter Deposit Amout : ", clsInput::Positive);

	if (YesNoQuestion() == clsScreen::No)
	{
		cout << "Operation Canceld\n";
		return;
	}

	PrintStaus(Clint.Deposit(DepositAmount));


	Header();
	clsScreen::Line(80);
	PrintClintInfo(Clint);
	clsScreen::Line(80);
}

//----------------------------
// Static Private Methods
//----------------------------

void clsDepositScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tD E P O S I T", 55);
}

clsClint clsDepositScreen::GetClint()
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
