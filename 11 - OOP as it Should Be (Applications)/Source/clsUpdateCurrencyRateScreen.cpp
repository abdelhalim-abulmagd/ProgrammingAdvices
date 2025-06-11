#include "clsUpdateCurrencyRateScreen.h"
#include "clsInput.h"

clsUpdateCurrencyRateScreen::~clsUpdateCurrencyRateScreen() {}

//----------------------------
// Static Public Methods
//----------------------------
void clsUpdateCurrencyRateScreen::Show()
{
	system("cls");
	clsScreen::Header("\t\tU P D A T E - C U R R E N C Y - R A T E", 55);

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

	float NewRate = clsInput::ReadNumber("Enter New Rate : ", clsInput::Positive);

	if (YesNoQuestion() == clsScreen::No)
	{
		cout << "Operation Canceld\n";
		return;
	}

	clsCurrency::EnStatus Status = Currency.UpdateRate(NewRate);

	if (Status != clsCurrency::Success)
	{
		PrintStaus(Status);
		return;
	}

	system("cls");
	clsScreen::Header("\t\tU P D A T E - C U R R E N C Y - R A T E", 55);

	Line(80);
	PrintCurrencyLable();
	PrintCurrencyInfo(Currency);
	Line(80);
	
	PrintStaus(Status);

}
