#pragma once

#include "clsScreen.h"

class clsClintMainScreen : public clsScreen
{
public:
	clsClintMainScreen();
	virtual ~clsClintMainScreen();

	static void Show();

private:
	enum EnMenuChoices { ShowListClints = 1, Add, Delete, Update, Transaction, ManageUsers, Log, CurrencyExchange, Logout };

	static void PerformMenuChoice(EnMenuChoices Choice);

	static void BackToMainScreen();


};