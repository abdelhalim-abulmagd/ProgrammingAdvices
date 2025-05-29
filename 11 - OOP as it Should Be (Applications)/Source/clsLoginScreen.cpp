#include "clsLoginScreen.h"
#include "clsClintMainScreen.h"

#include "clsClint.h"
#include "clsInput.h"

#include "Global.h"

clsLoginScreen::clsLoginScreen() {}


clsLoginScreen::~clsLoginScreen() {}

void clsLoginScreen::Show()
{
	system("cls");
	clsScreen::Header("\t\tL O G I N", 55);

	if (Login() == Success)
	{
		Global::CurrentUser->SaveLog();
		clsClintMainScreen::Show();
	}

}


clsLoginScreen::EnStatus clsLoginScreen::Login()
{
	bool LoginSuccess = false;

	do
	{
		string UserName = clsInput::ReadString("Enter User Name : ");
		string Password = clsInput::ReadString("Enter Password : ");

		*Global::CurrentUser = clsUser(UserName, Password);

		LoginSuccess = (Global::CurrentUser->GetUserStatus() == clsUser::UserExist);

		if (!LoginSuccess)
			cout << "Wrong User Name Or Password\n";

	} while (!LoginSuccess);


	return Success;
}
