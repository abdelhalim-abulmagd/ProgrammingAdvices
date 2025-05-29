#pragma once

#include "clsScreen.h"

class clsListClintScreen : public clsScreen
{
public:
	clsListClintScreen();
	virtual ~clsListClintScreen();

	static void Show();

private:

	static void Header(short CLintCount);

	static void PrintListClint( vector<clsClint>& vClints);
};