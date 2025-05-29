#include "clsLogScreen.h"
#include <iomanip>
#include <iostream>

using namespace std;

clsLogScreen::clsLogScreen() {}

clsLogScreen::~clsLogScreen() {}


//----------------------------
// Static Public Methods
//----------------------------

void clsLogScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::clsLogScreen))
		return;

	vector<clsUser::StLog> vLog;

	if (clsUser::GetLog(vLog) == clsUser::FileNotFound)
	{
		clsScreen::PrintStaus(clsUser::FileNotFound);
		return;
	}

	Header(vLog.size());

	PrintLogList(vLog);
}

//----------------------------
// Static Private Methods
//----------------------------


void clsLogScreen::Header(short LogCount)
{
	system("cls");

	string Message = "\t\tL O G -L I S T - [" + to_string(LogCount) + "]-Logs";

	clsScreen::Header(Message, 65);

}

void clsLogScreen::PrintLogList(vector<clsUser::StLog> vLog)
{
	
	cout << left;

	cout << "|" << setw(25) << "Date";
	cout << "|" << setw(12) << "User Name";
	cout << "|" << setw(10) << "Password";
	cout << "|" << setw(10) << "Permessions" << '\n';

	clsScreen::Line(65);


	for (clsUser::StLog &Log : vLog)
	{
		cout << "|" << setw(25) << Log.Date; 
		cout << "|" << setw(12) << Log.UserName;
		cout << "|" << setw(10) << Log.Password;
		cout << "|" << setw(10) << Log.Permissions << '\n';
	}
	clsScreen::Line(65);

}

