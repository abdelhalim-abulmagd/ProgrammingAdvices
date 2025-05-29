#pragma once

#include "clsScreen.h"
#include "clsClint.h"

class clsDepositScreen : protected clsScreen
{
public:
	clsDepositScreen();
	virtual ~clsDepositScreen();

	static void Show();
private:

	static void Header();

	static clsClint GetClint();

};