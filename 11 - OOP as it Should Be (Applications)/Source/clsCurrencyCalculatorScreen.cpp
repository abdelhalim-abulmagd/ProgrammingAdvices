#include "clsCurrencyCalculatorScreen.h"
#include "clsInput.h"

clsCurrencyCalculatorScreen::~clsCurrencyCalculatorScreen() {}

//----------------------------
// Static Public Methods
//----------------------------
void clsCurrencyCalculatorScreen::Show()
{
	system("cls");
	clsScreen::Header("\t\tC U R R E N C Y - C A L C U L A T O R", 55);

	if (clsCurrency::GetDataFileStatus() == clsCurrency::DataFileNotFound)
	{
		PrintStaus(clsCurrency::DataFileNotFound);
		return;
	}

	string CodeOrCountryCurrency1 = clsInput::ReadString("Enter [ Code or Country ] Currency 1 : ");

	clsCurrency Currency1 = clsCurrency(CodeOrCountryCurrency1);

	if (Currency1.GetCurrencyStatus() == clsCurrency::CurrencyNotExist)
	{
		PrintStaus(clsCurrency::CurrencyNotExist);
		return;
	}

	string CodeOrCountryCurrency2 = clsInput::ReadString("Enter [ Code or Country ] Currency 2 : ");

	clsCurrency Currency2 = clsCurrency(CodeOrCountryCurrency2);

	if (Currency2.GetCurrencyStatus() == clsCurrency::CurrencyNotExist)
	{
		PrintStaus(clsCurrency::CurrencyNotExist);
		return;
	}

	float Amount = clsInput::ReadNumber("Enter Amount To Convert : ", clsInput::Positive);

	float ConvertedAmount = Currency1.convertTo(Currency2, Amount);

	cout << Amount << " " << CodeOrCountryCurrency1 << " = " << ConvertedAmount << " " << CodeOrCountryCurrency2 << '\n';

}
