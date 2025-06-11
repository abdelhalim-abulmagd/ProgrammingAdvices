#include "CurrencyExchangeScreen.h"

#include "clsListCurrenciesScreen.h"
#include "clsFindCurrencyScreen.h"
#include "clsUpdateCurrencyRateScreen.h"
#include "clsCurrencyCalculatorScreen.h"


#include "clsInput.h"

clsCurrencyExchangeScreen::~clsCurrencyExchangeScreen() {}


//----------------------------
// Static Public Methods
//----------------------------

void clsCurrencyExchangeScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::ShowClintsListScreen))
		return;

	system("cls");
	clsScreen::Header("\t\C U R R E N C Y - E C H A N G E - M E N U", 55);

	vector<string> Choices
	{
		"List Currencies",
		"Find Currency",
		"Update Rate",
		"Currency Calculator",
		"Main Menu"
	};

	clsScreen::PrintMenuChoices(Choices);

	clsScreen::Line(55);

	EnMenuChoices Choice = static_cast<EnMenuChoices>(clsInput::ReadNumber("Chose From [1, 5] : ", 1, 5));

	PerformMenuChoice(Choice);
}

//----------------------------
// Static Private Methods
//----------------------------



void clsCurrencyExchangeScreen::PerformMenuChoice(EnMenuChoices Choice)
{

	switch (Choice)
	{
	case ListCurrencies:
		clsListCurrenciesScreen::Show();
		break;
	case Find:
		clsFindCurrencyScreen::Show();
		break;
	case Update:
		clsUpdateCurrencyRateScreen::Show();
		break;
	case Calculator:
		clsCurrencyCalculatorScreen::Show();
		break;
	case MainMenu:
		return;
	}

	BackToMainScreen();
}

void clsCurrencyExchangeScreen::BackToMainScreen()
{
	cout << "Enter Any Key To Back To Currency Exchange Menu Screen...";
	system("pause>0");
	Show();

}