#include "clsClintMainScreen.h"
#include "clsInput.h"

#include "clsAddClintScreen.h"
#include "clsDeleteClintScreen.h"
#include "clsListClintScreen.h"
#include "clsUpdateClintScreen.h"
#include "clsTransactionMenuScreen.h"
#include "clsManageUsersScreen.h"
#include "clsLogScreen.h"

#include "clsLoginScreen.h"
#include "Global.h"
#include "clsUser.h"


clsClintMainScreen::clsClintMainScreen() {}

clsClintMainScreen::~clsClintMainScreen(){}

//----------------------------
// Static Public Methods
//----------------------------

void clsClintMainScreen::Show()
{

	system("cls");
	clsScreen::Header("\t\tM A I N - M E N U", 55);

	vector<string> Choices
	{
		"Show Clint List",
		"Add New Clint",
		"Delete Clint",
		"Update Clint",
		"Transactions",
		"Manage Users",
		"Log",
		"Logout"
	};

	clsScreen::PrintMenuChoices(Choices);

	clsScreen::Line(55);

	EnMenuChoices Choice = static_cast<EnMenuChoices>(clsInput::ReadNumber("Chose From [1, 8] : ", 1, 8));

	PerformMenuChoice(Choice);
}


//----------------------------
// Static Private Methods
//----------------------------


void clsClintMainScreen::PerformMenuChoice(EnMenuChoices Choice)
{

	switch (Choice)
	{
	case ShowListClints:
		clsListClintScreen::Show();
		break;
	case Add:
		clsAddClintScreen::Show();
		break;
	case Delete:
		clsDeleteClintScreen::Show();
		break;
	case Update:
		clsUpdateClintScreen::Show();
		break; 
	case Transaction:
		clsTransactionMenuScreen::Show();
		break;
	case ManageUsers:
		clsManageUsersScreen::Show();
		break;
	case Log:
		clsLogScreen::Show();
		break;
	case Logout:
		*Global::CurrentUser = clsUser("");
		clsLoginScreen::Show();
		break;
	}
	BackToMainScreen();
}

void clsClintMainScreen::BackToMainScreen()
{
	cout << "Enter Any Key To Back To Main Menu Screen...";
	system("pause>0");
	Show();

}

