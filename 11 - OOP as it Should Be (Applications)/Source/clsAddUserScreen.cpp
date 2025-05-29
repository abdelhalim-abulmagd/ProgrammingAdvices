#include "clsAddUserScreen.h"

#include "clsUser.h"
#include "clsInput.h"

//---------------------------
// Static Private Methods
//---------------------------

clsAddUserScreen::clsAddUserScreen() { }

clsAddUserScreen::~clsAddUserScreen() { }

void clsAddUserScreen::Show()
{
	Header();
	clsUser::EnStatus Status = AddUser();

	clsScreen::PrintStaus(Status);

}

//---------------------------
// Static Private Methods
//---------------------------

void clsAddUserScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tA D D - U S E R", 55);

}

clsUser::EnStatus clsAddUserScreen::AddUser()
{
	clsUser User("");

	bool UserExist = true;

	do
	{
		string UserName = clsInput::ReadString("Enter User Name : ");

		User = clsUser(UserName);


		UserExist = (User.GetUserStatus() == clsUser::UserExist);

		if (UserExist)
			clsScreen::PrintStaus(clsUser::UserExist);

	} while (UserExist);

	User = ReadUserInfo(User);

	return User.AddToFile();
}

clsUser clsAddUserScreen::ReadUserInfo(clsUser User)
{
	User.SetFirstName(clsInput::ReadString("First Name : "));
	User.SetLastName(clsInput::ReadString("Last Name : "));
	User.SetEmail(clsInput::ReadString("Email : "));
	User.SetPhone(clsInput::ReadString("Phone : "));
	
	User.SetPassword(clsInput::ReadString("Password : "));
	User.SetPermissions(ReadPermission());

	return User;
}

int clsAddUserScreen::ReadPermission()
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

	if (YesNoQuestion("Give Him Accsess On > Log Screen < [Y, n]: ") == Yes)
		Permissios = Permissios | Log;

	return Permissios;

}