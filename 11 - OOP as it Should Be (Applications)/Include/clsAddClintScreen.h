#pragma once

#include "clsScreen.h"

class clsAddClintScreen : public clsScreen
{
public:
	clsAddClintScreen();
	virtual ~clsAddClintScreen();

	static void Show();

private:
	
	static void Header();

	static clsClint::EnStatus AddClint();

	static clsClint ReadClintInfo(clsClint Clint);

};
