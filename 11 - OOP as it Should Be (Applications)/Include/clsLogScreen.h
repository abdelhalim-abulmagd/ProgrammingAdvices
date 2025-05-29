#pragma once

#include "clsScreen.h"


class clsLogScreen : public clsScreen
{
public:
	clsLogScreen();
	virtual ~clsLogScreen();

	static void Show();

private:

	static void Header(short LogCount);

	static void PrintLogList(vector<clsUser::StLog> vLog);

};