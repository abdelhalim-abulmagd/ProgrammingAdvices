#pragma once

#include "clsScreen.h"

class clsListCurrenciesScreen : protected clsScreen
{
public:
	virtual ~clsListCurrenciesScreen();

	static void Show();

private:

	static void Header(short CurrenciesCount);

	static void PrintListCurrencies(vector<clsCurrency>& vCurrencies);
};