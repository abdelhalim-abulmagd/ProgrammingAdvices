#pragma once

#include "clsScreen.h"

#include "clsUser.h"


class clsUpdateUserScreen : protected clsScreen
{
public:
	clsUpdateUserScreen();
	virtual ~clsUpdateUserScreen();

	static void Show();

private:

	enum EnPermissios {
		AllPermissios = -1, ShowClintList = 1, AddNewClint = 2, DeleteClint = 4, UpdateClint = 8,
		Transaction = 16, ManageUsers = 32
	};

	static void Update();

	static clsUser GetUser();

	static clsUser ReadUserInfo(clsUser User);

	static void Header();

	static int ReadPermission();

};