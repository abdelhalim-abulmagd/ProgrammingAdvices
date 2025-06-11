#pragma once

#include "clsScreen.h"

class clsCurrencyExchangeScreen : protected clsScreen
{
public:
	virtual ~clsCurrencyExchangeScreen();

	static void Show();


private:
	enum EnMenuChoices { ListCurrencies = 1, Find, Update, Calculator, MainMenu };

	static void PerformMenuChoice(EnMenuChoices Choice);

	static void BackToMainScreen();
};