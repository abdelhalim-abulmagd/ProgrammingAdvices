#pragma once

#include "clsScreen.h"

class clsManageUsersScreen : public clsScreen
{
public:
	clsManageUsersScreen();
	virtual ~clsManageUsersScreen();

	static void Show();

private:

	enum EnMenuChoices { ListUsers = 1, Add = 2, Delete = 3, Update = 4, MainMenu = 5 };

	static void PerformMenuChoice(EnMenuChoices Choice);

	static void BackToMainScreen();
};