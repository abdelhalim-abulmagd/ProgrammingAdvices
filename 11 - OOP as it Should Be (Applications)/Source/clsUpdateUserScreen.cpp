#include "clsUpdateUserScreen.h"
#include "clsInput.h"

#include <string>
#include <iostream>

using namespace std;

//----------------------------
// Static Public Methods
//----------------------------

clsUpdateUserScreen::clsUpdateUserScreen() {}

clsUpdateUserScreen::~clsUpdateUserScreen() {}

void clsUpdateUserScreen::Show()
{
	Header();
	Update();
}


//----------------------------
// Static Private Methods
//----------------------------

void clsUpdateUserScreen::Update()
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

	User = ReadUserInfo(User);

	clsUser::EnStatus Status = User.Update();
	
	PrintStaus(Status);
}

clsUser clsUpdateUserScreen::GetUser()
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

clsUser clsUpdateUserScreen::ReadUserInfo(clsUser User)
{
	User.SetFirstName	(clsInput::ReadString			("First Name : "));
	User.SetLastName	(clsInput::ReadString			("Last Name : "));
	User.SetEmail		(clsInput::ReadString			("Email : "));
	User.SetPhone		(clsInput::ReadString			("Phone : "));

	User.SetPassword	(clsInput::ReadString			("Password : "));
	User.SetPermissions(ReadPermission());

	return User;
}

void clsUpdateUserScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tU P D A T E - U S E R", 55);

}

int clsUpdateUserScreen::ReadPermission()
{
	int Permissios = 0;

	if (YesNoQuestion("Give Him Full Accsess [Y, n]: ") == Yes)
		return AllPermissios;


	if (YesNoQuestion("Give Him Accsess On > Show Clint List < [Y, n]: ") == Yes)
		Permissios = Permissios | ShowClintList;

	if (YesNoQuestion("Give Him Accsess On > Add New Clint < [Y, n]: ") == Yes)
		Permissios = Permissios | AddNewClint;

	if (YesNoQuestion("Give Him Accsess On > Delete Clint < [Y, n]: ") == Yes)
		Permissios = Permissios | DeleteClint;

	if (YesNoQuestion("Give Him Accsess On > Update Clint < [Y, n]: ") == Yes)
		Permissios = Permissios | UpdateClint;

	if (YesNoQuestion("Give Him Accsess On > Transactions < [Y, n]: ") == Yes)
		Permissios = Permissios | Transaction;

	if (YesNoQuestion("Give Him Accsess On > Manage Users < [Y, n]: ") == Yes)
		Permissios = Permissios | ManageUsers;

	return Permissios;

}