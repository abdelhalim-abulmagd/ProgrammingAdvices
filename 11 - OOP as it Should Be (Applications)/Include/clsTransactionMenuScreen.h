#pragma once

#include "clsScreen.h"

class clsTransactionMenuScreen : protected clsScreen
{
public:
	clsTransactionMenuScreen();
	virtual ~clsTransactionMenuScreen();

	static void Show();


private:
	enum EnMenuChoices { Deposit = 1, Withdraw,  MainMenu };

	static void PerformMenuChoice(EnMenuChoices Choice);

	static void BackToMainScreen();
};