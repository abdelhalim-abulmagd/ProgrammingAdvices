#include "clsFindCurrencyScreen.h"
#include "clsInput.h"

clsFindCurrencyScreen::~clsFindCurrencyScreen() {}

//----------------------------
// Static Public Methods
//----------------------------
void clsFindCurrencyScreen::Show()
{
	system("cls");
	clsScreen::Header("\t\tF I N D - C U R R E N C Y", 55);

	if (clsCurrency::GetDataFileStatus() == clsCurrency::DataFileNotFound)
	{
		PrintStaus(clsCurrency::DataFileNotFound);
		return;
	}

	string CodeOrCountry = clsInput::ReadString("Enter [ Code or Country ] : ");

	clsCurrency Currency = clsCurrency(CodeOrCountry);

	if (Currency.GetCurrencyStatus() == clsCurrency::CurrencyNotExist)
	{
		PrintStaus(clsCurrency::CurrencyNotExist);
		return;
	}

	Line(80);
	PrintCurrencyLable();
	PrintCurrencyInfo(Currency);
	Line(80);
}
