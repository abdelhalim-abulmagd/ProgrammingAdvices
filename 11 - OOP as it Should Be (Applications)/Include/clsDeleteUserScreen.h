#pragma once

#include "clsScreen.h"

class clsDeleteUserScreen : protected clsScreen
{
public:
	
	clsDeleteUserScreen();
	
	virtual ~clsDeleteUserScreen();

	static void Show();

private:
	
	static void Header();

	static void Delete();

	static clsUser GetUser();
};