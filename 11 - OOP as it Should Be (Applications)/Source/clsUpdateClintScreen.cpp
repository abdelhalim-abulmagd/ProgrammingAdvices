#include "clsUpdateClintScreen.h"
#include "clsInput.h"

#include <string>
#include <iostream>

using namespace std;

//----------------------------
// Static Public Methods
//----------------------------

clsUpdateClintScreen::clsUpdateClintScreen() {}

clsUpdateClintScreen::~clsUpdateClintScreen() {}

void clsUpdateClintScreen::Show()
{
	if (!clsScreen::HasPermission(clsUser::UpdateClintScreen))
		return;

	Header();
	Update();
}


//----------------------------
// Static Private Methods
//----------------------------

void clsUpdateClintScreen::Update()
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

	Clint = ReadClintInfo(Clint);

	clsClint::EnStatus Status = Clint.Update();
	
	PrintStaus(Status);
}

clsClint clsUpdateClintScreen::GetClint()
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

clsClint clsUpdateClintScreen::ReadClintInfo(clsClint Clint)
{
	Clint.SetFirstName	(clsInput::ReadString			("First Name : "));
	Clint.SetLastName	(clsInput::ReadString			("Last Name : "));
	Clint.SetEmail		(clsInput::ReadString			("Email : "));
	Clint.SetPhone		(clsInput::ReadString			("Phone : "));

	Clint.SetPinCode	(clsInput::ReadString			("Pin Code : "));
	Clint.SetSalary		(clsInput::ReadNumber			("Salary : ", clsInput::Positive));

	return Clint;
}

void clsUpdateClintScreen::Header()
{
	system("cls");
	clsScreen::Header("\t\tU P D A T E - C L I N T", 55);

}

