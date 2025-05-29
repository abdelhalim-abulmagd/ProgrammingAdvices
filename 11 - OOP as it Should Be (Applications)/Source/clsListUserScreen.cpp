#include "clsInput.h"
#include "clsString.h"
#include "clsListUserScreen.h"
#include <iomanip>

clsListUserScreen::clsListUserScreen(){}

clsListUserScreen::~clsListUserScreen(){}

//----------------------------
// Static Public Methods
//----------------------------

void clsListUserScreen::Show()
{
	vector<clsUser> vUsers;

	if (clsUser::ReadFromFile(vUsers) == clsUser::FileNotFound)
	{
		clsScreen::PrintStaus(clsUser::FileNotFound);
		return;
	}

	Header(vUsers.size());

	PrintListClint(vUsers);
}

//----------------------------
// Static Private Methods
//----------------------------


void clsListUserScreen::Header(short UsersCount)
{
	system("cls");

	string Message = "\t\tL I S T - U S E R S - [" + to_string(UsersCount) + "]-users";

	clsScreen::Header(Message, 80);

}

void clsListUserScreen::PrintListClint( vector<clsUser>& vUsers)
{
	clsScreen::UserInfoLable();

	clsScreen::Line(80);


	for (clsUser& User : vUsers)
	{
		clsScreen::PrintUserInfo(User);
	}
	
	clsScreen::Line(80);

}

