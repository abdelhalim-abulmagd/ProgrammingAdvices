#pragma once

#include "clsScreen.h"

class clsClintMainScreen : public clsScreen
{
public:
	clsClintMainScreen();
	virtual ~clsClintMainScreen();

	static void Show();

private:
	enum EnMenuChoices { ShowListClints = 1, Add, Delete, Update, Transaction, ManageUsers, Log, Logout };

	static void PerformMenuChoice(EnMenuChoices Choice);

	static void BackToMainScreen();


};