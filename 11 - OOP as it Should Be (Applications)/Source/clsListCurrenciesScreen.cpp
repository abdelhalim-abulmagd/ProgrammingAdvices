#include "clsListCurrenciesScreen.h"

#include "clsInput.h"
#include "clsString.h"
#include "clsCurrency.h"

#include <iomanip>

clsListCurrenciesScreen::~clsListCurrenciesScreen() {}

//----------------------------
// Static Public Methods
//----------------------------

void clsListCurrenciesScreen::Show()
{
	vector<clsCurrency> vCurrencies;

	if (clsCurrency::ReadFromFile(vCurrencies) == clsCurrency::DataFileNotFound)
	{
		clsScreen::PrintStaus(clsCurrency::DataFileNotFound);
		return;
	}

	Header(vCurrencies.size());

	PrintListCurrencies(vCurrencies);
}

//----------------------------
// Static Private Methods
//----------------------------


void clsListCurrenciesScreen::Header(short CurrenciesCount)
{
	system("cls");

	string Message = "\t\tC U R R E N C I E S - [" + to_string(CurrenciesCount) + "]-currency";

	clsScreen::Header(Message, 80);

}

void clsListCurrenciesScreen::PrintListCurrencies(vector<clsCurrency>& vCurrencies)
{
	clsScreen::PrintCurrencyLable();

	clsScreen::Line(80);


	for (clsCurrency& Currency : vCurrencies)
	{
		clsScreen::PrintCurrencyInfo(Currency);
	}

	clsScreen::Line(80);

}

