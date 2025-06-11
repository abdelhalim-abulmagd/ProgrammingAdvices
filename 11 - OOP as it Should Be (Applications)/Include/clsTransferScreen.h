#pragma once

#include "clsScreen.h"

class clsTransferScreen : protected clsScreen
{
public:

	static void Show();

private:

	static void Header();

	static clsClint GetClint(string Message);

	static void PrintClintInfo(clsClint Clint);
};