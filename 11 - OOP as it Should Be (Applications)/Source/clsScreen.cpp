#include <iomanip>
#include <iostream>

#include "clsScreen.h"
#include "Global.h"
#include "clsDate.h"

using namespace std;

//----------------------------
// Static Public Methods
//----------------------------

clsScreen::clsScreen() { }

clsScreen::~clsScreen() { }

void clsScreen::Header(const string& Text, const short& LineWidth)
{
	cout << "Date :" << clsDate::FormatDate(clsDate()) << " ";
	cout << "User : " << Global::CurrentUser->GetFullName() << '\n';
	cout << Text << "\n";

	Line(LineWidth);
}

void clsScreen::PrintClintInfo( clsClint& Clint)
{
	cout << left;

	cout << "|" << setw(20) << Clint.GetFullName();
	cout << "|" << setw(18) << Clint.GetEmail();
	cout << "|" << setw(10) << Clint.GetPhone();
	cout << "|" << setw(12) << Clint.GetAcountNumber();
	cout << "|" << setw(8) << Clint.GetPinCode();
	cout << "|" << setw(10) << Clint.GetCurrentBalance() << '\n';
}

void clsScreen::PrintUserInfo(clsUser& User)
{
	cout << left;

	cout << "|" << setw(20) << User.GetFullName();
	cout << "|" << setw(18) << User.GetEmail();
	cout << "|" << setw(10) << User.GetPhone();
	cout << "|" << setw(12) << User.GetUserName();
	cout << "|" << setw(8) << User.GetPassword();
	cout << "|" << setw(10) << User.GetPermissions() << '\n';
}

void clsScreen::PrintCurrencyLable()
{
	cout << left;

	cout << "|" << setw(30) << "Country";
	cout << "|" << setw(5) << "Code";
	cout << "|" << setw(35) << "Currency Name";
	cout << "|" << setw(5) << "Rate" << '\n';
}

void clsScreen::PrintCurrencyInfo(clsCurrency& Currency)
{
	cout << left;

	cout << "|" << setw(30) << Currency.GetCountry();
	cout << "|" << setw(5) << Currency.GetCode();
	cout << "|" << setw(35) << Currency.GetCurrencyName();
	cout << "|" << setw(5) << Currency.GetRate() << '\n';
}

void clsScreen::PrintStaus(clsClint::EnStatus Status)
{
	switch (Status)
	{
	case clsClint::FailedWriteToFile:
		cout << "Failed : Failed To Add New Updated Data To File\n";
		break;
	case clsClint::ClintNotFound:
		cout << "Failed : Clint Not Found On Data File\n";
		break;
	case clsClint::FileNotFound:
		cout << "Failed : Clints Data File Not Found \n";
		break;

	case clsClint::Success:
		cout << "Success : New Updated Data Saved To File Successfully\n";
		break;
	case clsClint::ClintExist:
		cout << "Info : Clint Exist\n";
		break;

	case clsClint::InvalidAmount:
		cout << "Failed : Invalid Amount\n";
		break;
	}
}

void clsScreen::PrintStaus(clsUser::EnStatus Status)
{
	switch (Status)
	{
	case clsUser::FailedWriteToFile:
		cout << "Failed : Failed To Add New Updated Data To File\n";
		break;

	case clsUser::UserNotFound:
		cout << "Failed : User Not Found On Data File\n";
		break;
	case clsUser::FileNotFound:
		cout << "Failed : Clints Data File Not Found \n";
		break;
		
	case clsUser::FileExist:
		cout << "Info : File Exist\n";
		break;

	case clsUser::UserExist:
		cout << "Info : User Exist\n";
		break;

	case clsUser::Success:
		cout << "Success : New Updated Data Saved To File Successfully\n";
		break;


	}
}


void clsScreen::PrintStaus(clsCurrency::EnStatus Status)
{
	switch (Status)
	{
	case clsCurrency::CurrencyNotExist:
		cout << "Failed : Currency Not Found On Data File\n";
		break;

	case clsCurrency::CurrencyExist:
		cout << "Info : Currency Exist On Data File\n";
		break;

	case clsCurrency::DataFileFound:
		cout << "Info : Data File Found \n";
		break;

	case clsCurrency::DataFileNotFound:
		cout << "Failed : Data File Not Found \n";
		break;

	case clsCurrency::Success:
		cout << "Success : New Updated Data Saved To File Successfully\n";
		break;

	}
}

clsScreen::EnAnwer clsScreen::YesNoQuestion(string Msg)
{
	string DefultMsg = "Are You Sure? [Y, n] : ";

	Msg = Msg == "" ? DefultMsg : Msg;

	char Answer;
	cout << Msg;
	cin >> Answer;

	return tolower(Answer) == 'y' ? clsScreen::Yes : clsScreen::No;
}

void clsScreen::Line(const short& LineWidth)
{
	for (size_t i = 0; i < LineWidth; i++)
		cout << '-';
	cout << '\n';
}

void clsScreen::ClintInfoLable()
{
	cout << left;

	cout << "|" << setw(20) << "Name";
	cout << "|" << setw(18) << "Email";
	cout << "|" << setw(10) << "Phone";
	cout << "|" << setw(12) << "AcountNumber";
	cout << "|" << setw(8) << "PinCode";
	cout << "|" << setw(10) << "Balance" << '\n';
}

void clsScreen::UserInfoLable()
{
	cout << left;

	cout << "|" << setw(20) << "Name";
	cout << "|" << setw(18) << "Email";
	cout << "|" << setw(10) << "Phone";
	cout << "|" << setw(12) << "User Name";
	cout << "|" << setw(8) << "Password";
	cout << "|" << setw(10) << "Permissions" << '\n';
}

void clsScreen::PrintMenuChoices(vector<string> Choices)
{
	for (size_t i = 0; i < Choices.size(); i++)
	{
		cout << "\t[" << i + 1 << "] " << Choices[i] << '\n';
	}
}

bool clsScreen::HasPermission(clsUser::EnPermissions Permission)
{
	if (Global::CurrentUser->HasPermission(Permission))
		return true;

	system("cls");
	cout << "You Dont Have Permission \n";

	return false;
}