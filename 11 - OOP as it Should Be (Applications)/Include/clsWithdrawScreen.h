#pragma once

#include "clsScreen.h"

class clsWithdrawScreen : protected clsScreen
{
public:
	clsWithdrawScreen();
	virtual ~clsWithdrawScreen();

	static void Show();
private:

	static void Header();

	static clsClint GetClint();

};