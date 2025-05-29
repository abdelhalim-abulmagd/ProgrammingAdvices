#pragma once

#include "clsScreen.h"

class clsLoginScreen : protected clsScreen 
{
public:
	clsLoginScreen();
	virtual ~clsLoginScreen();

	static void Show();

private:

	enum EnStatus { Success};

	static EnStatus Login();

};

