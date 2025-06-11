#include "clsInput.h"
#include "clsString.h"
#include "clsListClintScreen.h"
#include <iomanip>

clsListClintScreen::clsListClintScreen(){}

clsListClintScreen::~clsListClintScreen(){}

//----------------------------
// Static Public Methods
//----------------------------

void clsListClintScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::ShowClintsListScreen))
		return;


	vector<clsClint> vClints;

	if (clsClint::ReadFromFile(vClints) == clsClint::FileNotFound)
	{
		clsScreen::PrintStaus(clsClint::FileNotFound);
		return;
	}

	Header(vClints.size());

	PrintListClint(vClints);
}

//----------------------------
// Static Private Methods
//----------------------------


void clsListClintScreen::Header(short CLintCount)
{
	system("cls");

	string Message = "\t\tL I S T - C L I N T - [" + to_string(CLintCount) + "]-clints";

	clsScreen::Header(Message, 80);

}

void clsListClintScreen::PrintListClint( vector<clsClint>& vClints)
{
	clsScreen::ClintInfoLable();

	clsScreen::Line(80);

	float TotalBalance = 0.0f;

	for ( clsClint& Clint : vClints)
	{
		clsScreen::PrintClintInfo(Clint);
		TotalBalance += Clint.GetCurrentBalance();
	}
	clsScreen::Line(80);

	cout << "Total Balance : " << TotalBalance << " : " << clsString::NumberToText(TotalBalance) << '\n';
	
	clsScreen::Line(80);

}

