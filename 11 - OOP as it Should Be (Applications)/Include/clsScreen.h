#pragma once

#include "clsClint.h"
#include "clsUser.h"



#include <string>

using namespace std;

class clsScreen
{
public:
	clsScreen();
	virtual ~clsScreen();

	enum EnAnwer { No, Yes };

	static void Header(const string& Text, const short& LineWidth);

	static void PrintClintInfo(clsClint& Clint);

	static void PrintUserInfo(clsUser& User);

	static void PrintStaus(clsClint::EnStatus Status);

	static void PrintStaus(clsUser::EnStatus Status);

	static EnAnwer YesNoQuestion(string Msg = "");

	static void Line(const short& LineWidth);
	
	static void ClintInfoLable();

	static void UserInfoLable();

	static void PrintMenuChoices(vector<string> Choices);

	static bool HasPermission(clsUser::EnPermissions Permission );
};