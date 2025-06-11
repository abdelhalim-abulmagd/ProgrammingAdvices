#include "clsTransactionMenuScreen.h"

#include "clsDepositScreen.h"
#include "clsWithdrawScreen.h"
#include "clsTransferScreen.h"
#include "clsTransferLogScreen.h"

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
		"Transfer",
		"Tranfer Log",
		"Main Menu"
	};

	clsScreen::PrintMenuChoices(Choices);

	clsScreen::Line(55);

	EnMenuChoices Choice = static_cast<EnMenuChoices>(clsInput::ReadNumber("Chose From [1, 5] : ", 1, 5));

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
	case Transfer:
		clsTransferScreen::Show();
		break;
	case TransferLog:
		clsTransferLogScreen::Show();
		break;

	case MainMenu:
		return;
	}
	
	BackToMainScreen();
}

void clsTransactionMenuScreen::BackToMainScreen()
{
	cout << "Enter Any Key To Back To Transaction Menu Screen...";
	system("pause>0");
	Show();

}