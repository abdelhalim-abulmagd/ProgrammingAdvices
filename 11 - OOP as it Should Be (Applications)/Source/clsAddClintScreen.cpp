#include "clsAddClintScreen.h"

#include "clsClint.h"
#include "clsInput.h"

//---------------------------
// Static Private Methods
//---------------------------

clsAddClintScreen::clsAddClintScreen() { }

clsAddClintScreen::~clsAddClintScreen() { }

void clsAddClintScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::AddNewClintScreen))
		return;

	Header();
	clsClint::EnStatus Status = AddClint();

	clsScreen::PrintStaus(Status);

}

//---------------------------
// Static Private Methods
//---------------------------

void clsAddClintScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tA D D - C L I N T", 55);

}

clsClint::EnStatus clsAddClintScreen::AddClint()
{
	clsClint Clint("");

	bool ClintExist = true;

	do
	{
		string AccountNumber = clsInput::ReadString("Enter Account Number : ");

		Clint = clsClint(AccountNumber);

		ClintExist = (Clint.GetClintStatus() == clsClint::ClintExist);

		if (ClintExist)
			clsScreen::PrintStaus(clsClint::ClintExist);

	} while (ClintExist);

	Clint = ReadClintInfo(Clint);

	return Clint.AddToFile();
}

clsClint clsAddClintScreen::ReadClintInfo(clsClint Clint)
{
	Clint.SetFirstName(clsInput::ReadString("First Name : "));
	Clint.SetLastName(clsInput::ReadString("Last Name : "));
	Clint.SetEmail(clsInput::ReadString("Email : "));
	Clint.SetPhone(clsInput::ReadString("Phone : "));

	Clint.SetPinCode(clsInput::ReadString("Pin Code : "));
	Clint.SetCurrentBalance(clsInput::ReadNumber("Balance : ", clsInput::Positive));

	return Clint;
}