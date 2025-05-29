#include "clsDeleteUserScreen.h"
#include "clsInput.h"


clsDeleteUserScreen::clsDeleteUserScreen() {}

clsDeleteUserScreen::~clsDeleteUserScreen() {}

//----------------------------
// Static Public Methods
//----------------------------
void clsDeleteUserScreen::Show()
{
	Header();

	Delete();
}

//----------------------------
// Static Private Methods
//----------------------------

void clsDeleteUserScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tD E L E T E - U S E R", 55);
}

void clsDeleteUserScreen::Delete()
{
	if (clsUser::GetFileStatus() == clsUser::FileNotFound)
	{
		PrintStaus(clsUser::FileNotFound);
		return;
	}
	clsUser User = GetUser();

	Header();
	clsScreen::Line(80);

	PrintUserInfo(User);
	clsScreen::Line(80);

	if (YesNoQuestion() == clsScreen::No)
	{
		cout << "Operation Canceld\n";
		return;
	}

	PrintStaus(User.Delete());
	
}

clsUser clsDeleteUserScreen::GetUser()
{
	clsUser User("");

	bool UserNotFound = false;

	do
	{
		User = clsUser(clsInput::ReadString("Enter User Name : "));

		UserNotFound = (User.GetUserStatus() == clsUser::UserNotFound);

		if (UserNotFound)
			clsScreen::PrintStaus(clsUser::UserNotFound);

	} while (UserNotFound);

	return User;
}
