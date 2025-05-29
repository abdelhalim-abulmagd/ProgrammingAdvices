#include "clsManageUsersScreen.h"
#include "clsInput.h"

#include "clsListUserScreen.h"
#include "clsAddUserScreen.h"
#include "clsDeleteUserScreen.h"
#include "clsUpdateUserScreen.h"

clsManageUsersScreen::clsManageUsersScreen(){}

clsManageUsersScreen::~clsManageUsersScreen() {}


//----------------------------
// Static Public Methods
//----------------------------

void clsManageUsersScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::ManageUsersScreen))
		return;


	system("cls");
	clsScreen::Header("\t\tM A N A G E - U S  E R S", 55);

	vector<string> Choices
	{
		"List Users",
		"Add New Users",
		"Delete User",
		"Update User",
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


void clsManageUsersScreen::PerformMenuChoice(EnMenuChoices Choice)
{
	
	switch (Choice)
	{
	case ListUsers:
		clsListUserScreen::Show();
		break;
	case Add:
		clsAddUserScreen::Show();
		break;
	case Delete:
		clsDeleteUserScreen::Show();
		break;
	case Update:
		clsUpdateUserScreen::Show();
		break; 
	case MainMenu:
		return;
	}

	BackToMainScreen();
}

void clsManageUsersScreen::BackToMainScreen()
{
	cout << "Enter Any Key To Back To Main Menu Screen...";
	system("pause>0");
	Show();

}
