#pragma once

#include "clsScreen.h"

#include "clsClint.h"


class clsUpdateClintScreen : public clsScreen
{
public:
	clsUpdateClintScreen();
	virtual ~clsUpdateClintScreen();

	static void Show();

private:
	static void Update();

	static clsClint GetClint();

	static clsClint ReadClintInfo(clsClint Clint);

	static void Header();
};