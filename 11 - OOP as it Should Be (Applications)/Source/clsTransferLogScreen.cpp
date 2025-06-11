#include "clsTransferLogScreen.h"
#include <iomanip>
#include <iostream>

using namespace std;


//----------------------------
// Static Public Methods
//----------------------------

void clsTransferLogScreen::Show()
{
	vector<clsUser::StTransferLog> vTransferLog;

	if (clsUser::GetTransferLog(vTransferLog) == clsUser::FileNotFound)
	{
		clsScreen::PrintStaus(clsUser::FileNotFound);
		return;
	}

	Header(vTransferLog.size());

	PrintLogList(vTransferLog);
}

//----------------------------
// Static Private Methods
//----------------------------


void clsTransferLogScreen::Header(short LogCount)
{
	system("cls");

	string Message = "\t\tL O G -L I S T - [" + to_string(LogCount) + "]-Logs";

	clsScreen::Header(Message, 92);

}

void clsTransferLogScreen::PrintLogList(vector<clsUser::StTransferLog> vTransferLog)
{

	cout << left;

	cout << "|" << setw(20) << "Date";

	cout << "|" << setw(6) << "User";
	cout << "|" << setw(7) << "Amount";

	cout << "|" << setw(11) << "Source Acc";
	cout << "|" << setw(7) << "Before";
	cout << "|" << setw(7) << "After";

	cout << "|" << setw(11) << "Target Acc";
	cout << "|" << setw(7) << "Before";
	cout << "|" << setw(7) << "After" << '\n';

	clsScreen::Line(92);


	for (clsUser::StTransferLog& Log : vTransferLog)
	{
		cout << "|" << setw(20) << Log.Date;

		cout << "|" << setw(6) << Log.User;
		cout << "|" << setw(7) << Log.Amount;

		cout << "|" << setw(11) << Log.SourceAccount;
		cout << "|" << setw(7) << Log.SourceBalanceBefore;
		cout << "|" << setw(7) << Log.SourceBalanceAfter;

		cout << "|" << setw(11) << Log.TargetAccount;
		cout << "|" << setw(7) << Log.TargetBalanceBefore;
		cout << "|" << setw(7) << Log.TargetBalanceAfter << '\n';
	}
	clsScreen::Line(92);

}

