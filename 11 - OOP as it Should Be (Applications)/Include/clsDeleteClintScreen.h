#pragma once

#include "clsScreen.h"

class clsDeleteClintScreen : public clsScreen
{
public:
	
	clsDeleteClintScreen();
	
	virtual ~clsDeleteClintScreen();

	static void Show();

private:
	
	static void Header();

	static void Delete();

	static clsClint GetClint();
};