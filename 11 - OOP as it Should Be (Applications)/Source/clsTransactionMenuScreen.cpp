#include "clsTransactionMenuScreen.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"

#include "clsInput.h"
clsTransactionMenuScreen::clsTransactionMenuScreen() {}

clsTransactionMenuScreen::~clsTransactionMenuScreen() {}


//----------------------------
// Static Public Methods
//----------------------------

void clsTransactionMenuScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::ShowClintsListScreen))
		return;

	system("cls");
	clsScreen::Header("\t\T R A N S A C T I O N - M E N U", 55);

	vector<string> Choices
	{
		"Deposit",
		"Withdraw",
		"Main Menu"
	};

	clsScreen::PrintMenuChoices(Choices);

	clsScreen::Line(55);

	EnMenuChoices Choice = static_cast<EnMenuChoices>(clsInput::ReadNumber("Chose From [1, 3] : ", 1, 3));

	PerformMenuChoice(Choice);
}

//----------------------------
// Static Private Methods
//----------------------------



void clsTransactionMenuScreen::PerformMenuChoice(EnMenuChoices Choice)
{

	switch (Choice)
	{
	case Deposit:
		clsDepositScreen::Show();
		break;
	case Withdraw:
		clsWithdrawScreen::Show();
		break;
	case MainMenu:
		return;
	}
	
	BackToMainScreen();
}

void clsTransactionMenuScreen::BackToMainScreen()
{
	cout << "Enter Any Key To Back To Main Menu Screen...";
	system("pause>0");
	Show();

}