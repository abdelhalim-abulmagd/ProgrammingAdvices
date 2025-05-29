#pragma once

#include "clsScreen.h"

class clsAddUserScreen : protected clsScreen
{
public:
	clsAddUserScreen();
	virtual ~clsAddUserScreen();

	static void Show();

private:
	
	enum EnPermissios {
		AllPermissios = -1, ShowClintList = 1, AddNewClint = 2, DeleteClint = 4, UpdateClint = 8, 
		Transaction = 16, ManageUsers = 32 , Log};

	static void Header();

	static clsUser::EnStatus AddUser();

	static clsUser ReadUserInfo(clsUser User);

	static int ReadPermission();

};
