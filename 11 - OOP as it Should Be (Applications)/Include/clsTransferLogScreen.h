#pragma once

#include "clsScreen.h"


class clsTransferLogScreen : protected clsScreen
{
public:

	static void Show();

private:

	static void Header(short LogCount);

	static void PrintLogList(vector<clsUser::StTransferLog> vTransferLog);

};