#pragma once

#include "clsScreen.h"

class clsListUserScreen : protected clsScreen
{
public:
	clsListUserScreen();
	virtual ~clsListUserScreen();

	static void Show();

private:

	static void Header(short UsersCount);

	static void PrintListClint( vector<clsUser>& vUsers);
};