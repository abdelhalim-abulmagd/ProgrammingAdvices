#include "clsDeleteClintScreen.h"
#include "clsInput.h"



clsDeleteClintScreen::clsDeleteClintScreen() {}

clsDeleteClintScreen::~clsDeleteClintScreen() {}

//----------------------------
// Static Public Methods
//----------------------------
void clsDeleteClintScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::DeleteClintScreen))
		return;

	Header();

	Delete();
}

//----------------------------
// Static Private Methods
//----------------------------

void clsDeleteClintScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tD E L E T E - C L I N T", 55);
}

void clsDeleteClintScreen::Delete()
{
	if (clsClint::GetFileStatus() == clsClint::FileNotFound)
	{
		PrintStaus(clsClint::FileNotFound);
		return;
	}
	clsClint Clint = GetClint();

	Header();
	clsScreen::Line(80);

	PrintClintInfo(Clint);
	clsScreen::Line(80);

	if (YesNoQuestion() == clsScreen::No)
	{
		cout << "Operation Canceld\n";
		return;
	}

	PrintStaus(Clint.Delete());
	
}

clsClint clsDeleteClintScreen::GetClint()
{
	clsClint Clint("");

	bool ClintNotFound = false;

	do
	{
		Clint = clsClint(clsInput::ReadString("Enter Account Number : "));

		ClintNotFound = (Clint.GetClintStatus() == clsClint::ClintNotFound);

		if (ClintNotFound)
			clsScreen::PrintStaus(clsClint::ClintNotFound);

	} while (ClintNotFound);

	return Clint;
}
