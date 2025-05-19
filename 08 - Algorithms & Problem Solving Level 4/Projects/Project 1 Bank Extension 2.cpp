
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void BackToMainMenu();
void BackToTransactionsMenu();
void BackToMangageUsersMenu();

const string ClintsDataFilePath = "Clints.txt";
const string UsersDataFilePath = "Users.txt";

enum EnAnwer { No, Yes };
enum EnStatus { Fail, Success };
enum EnMainMenu { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6, ManageUsers=7, Logout = 8 };
enum EnTransactionMenu { Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4, };
enum EnManageUsersMenu { eListUsers = 1, eAdd = 2, eDelete = 3, eUpdate = 4, eFind = 5, eMainMenu = 6 };

enum EnPermissios { eAllPermissios = -1, eShowClintList = 1, eAddNewClint = 2, eDeleteClint = 3, eUpdateClint = 4, eFindClint = 5,
					eTransaction = 6, eManageUsers = 7 };

struct StUiSettings
{
	short LineWidth = 77;

	short AcountNumberWidth = 15;
	short PinCodeWidth = 10;
	short NameWidth = 20;
	short PhoneWidth = 20;
	short AcountBalanceWidth = 10;

};


struct StData
{
	string AcountNumber;
	string PinCode;
	string Name;
	string Phone;

	float AcountBalance;
};

struct StUser
{
	string UserName;
	string Password;
	int Permissions;
};

void PrintLine(int Width)
{
	for (size_t i = 0; i < Width; i++)
		cout << '-';
	cout << '\n';
}

void PrintHeader(string Msg, int Width)
{

	PrintLine(Width);

	cout << Msg << "\n";

	PrintLine(Width);

}



void PrintScreenChoice(vector<string> Choices)
{
	for (size_t i = 0; i < Choices.size(); i++)
	{
		cout << "\t[" << i + 1 << "] " << Choices[i] << '\n';
	}
}

void PrintMenuWithChoices(vector<string> Choices, string MenuHeaderName, StUiSettings UiSettings = StUiSettings())
{

	PrintHeader("\t\t" + MenuHeaderName, UiSettings.LineWidth);

	PrintScreenChoice(Choices);

	PrintLine(UiSettings.LineWidth);
}

bool IsInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

short ReadNumberInRange(string Msg, int From, int To)
{
	int Number;

	do
	{
		cout << Msg;
		cin >> Number;

	} while (!IsInRange(Number, From, To));

	return Number;
}


vector<string> Split(string String, string Separator = " ")
{
	int Position = 0;
	string Word;
	vector<string> SparatedString;

	while ((Position = String.find(Separator)) != string::npos)
	{
		Word = String.substr(0, Position);

		if (Word != "")
			SparatedString.push_back(Word);
		String.erase(0, Position + Separator.length());
	}

	if (String != "")
		SparatedString.push_back(String);

	return SparatedString;
}
StData RecordToData(string String, string Separator = "#//#")
{
	StData Data;

	vector<string> SparatedString = Split(String, Separator);

	Data.AcountNumber = SparatedString[0];
	Data.PinCode = SparatedString[1];
	Data.Name = SparatedString[2];
	Data.Phone = SparatedString[3];
	Data.AcountBalance = stof(SparatedString[4]);

	return Data;
}

vector<StData> ReadFromFile(string FilePath)
{
	vector<StData> vData;

	fstream File;
	File.open(FilePath, ios::in);

	if (File.is_open())
	{
		string Line;
		while (getline(File, Line))
			vData.push_back(RecordToData(Line));
	}

	return vData;
}

void PrintLable(int ClintCount, string Person = "Clint")
{
	cout << "\t\t\t"+ Person +" List [" << ClintCount << "] "+ Person +"(s)\n";
}

void PrintHeader(StUiSettings UiSettings)
{
	PrintLine(UiSettings.LineWidth);

	cout << left;
	cout << "|" << setw(UiSettings.AcountNumberWidth) << "Acount Number";
	cout << "|" << setw(UiSettings.PinCodeWidth) << "Pin Code";
	cout << "|" << setw(UiSettings.NameWidth) << "Clint Name";
	cout << "|" << setw(UiSettings.PhoneWidth) << "Phone Number";
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << "Balance";
	cout << '\n';

	PrintLine(UiSettings.LineWidth);
}

void PrintData(StData Data, StUiSettings UiSettings)
{
	cout << left;

	cout << "|" << setw(UiSettings.AcountNumberWidth) << Data.AcountNumber;
	cout << "|" << setw(UiSettings.PinCodeWidth) << Data.PinCode;
	cout << "|" << setw(UiSettings.NameWidth) << Data.Name;
	cout << "|" << setw(UiSettings.PhoneWidth) << Data.Phone;
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << Data.AcountBalance << '\n';
}


void PrintVData(vector<StData> vData, StUiSettings UiSettings)
{
	for (StData Data : vData)
		PrintData(Data, UiSettings);
}


void PrintFooter(int Width)
{
	PrintLine(Width);
}

void PrintClintsList(vector<StData> vData)
{
	StUiSettings UiSettings;

	PrintLable(vData.size());
	PrintHeader(UiSettings);
	PrintVData(vData, UiSettings);
	PrintFooter(UiSettings.LineWidth);
}

void ClintsList()
{
	system("cls");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);
	PrintClintsList(vData);
}



EnAnwer YesNoQuestion(string Msg = "")
{
	string DefultMsg = "Are You Sure? [Y, n] : ";

	Msg = Msg == "" ? DefultMsg : Msg;

	char Answer;
	cout << Msg;
	cin >> Answer;

	return tolower(Answer) == 'y' ? Yes : No;
}

StData ReadClint()
{
	StData Data;

	cout << "Acount Number : ";
	getline(cin >> ws, Data.AcountNumber);

	cout << "Pin Code : ";
	getline(cin, Data.PinCode);

	cout << "Name : ";
	getline(cin, Data.Name);

	cout << "Phone : ";
	getline(cin, Data.Phone);

	cout << "Acount Balance : ";
	cin >> Data.AcountBalance;


	return Data;
}

vector<StData> ReadClints()
{
	vector<StData> vClints;

	do
	{
		vClints.push_back(ReadClint());
	} while (YesNoQuestion() == Yes);

	return vClints;
}



void PrintAddNewClintsScreen()
{
	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t A D D - N E W - C L I N T S", UiSettings.LineWidth);

}

string DataToRecord(StData Data, string Separator = "#//#")
{
	string Record;

	Record += Data.AcountNumber + Separator;
	Record += Data.PinCode + Separator;
	Record += Data.Name + Separator;
	Record += Data.Phone + Separator;
	Record += to_string(Data.AcountBalance);

	return Record;
}


EnStatus AddToFile(vector<StData> vData, string FilePath)
{
	fstream File;

	File.open(FilePath, ios::out | ios::app);

	if (!File.is_open())
		Fail;

	for (StData Data : vData)
		File << DataToRecord(Data) + '\n';

	File.close();

	return Success;
}

EnStatus WriteToFile(vector<StData> vData, string FilePath)
{
	fstream File;

	File.open(FilePath, ios::out);

	if (!File.is_open())
		Fail;

	for (StData Data : vData)
		File << DataToRecord(Data) + '\n';

	File.close();

	return Success;
}


void AddNewClints()
{
	PrintAddNewClintsScreen();
	vector<StData> vClints = ReadClints();
	AddToFile(vClints, ClintsDataFilePath);
}

string ReadString(string Msg)
{
	string AccountNumber;
	cout << Msg;
	getline(cin >> ws, AccountNumber);
	return AccountNumber;
}

void PrintDeleteClintScreen()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t D E L E T E - C L I N T", UiSettings.LineWidth);

}

bool IsClintExist(string AccountNumber, vector<StData> vData, string FilePath)
{

	for (StData Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
			return true;
	}
	return false;

}

vector<StData> DeleteClintFromVector(string AccountNumber, vector<StData> vData)
{
	vector<StData>::iterator Iterator = vData.begin();

	for (Iterator; Iterator != vData.end(); Iterator++)
	{
		StData Data = *Iterator;

		if (Data.AcountNumber == AccountNumber)
		{
			vData.erase(Iterator);
			return vData;
		}
	}
}


void PrintClintInfo(StData Data)
{
	StUiSettings UiSettings;

	PrintHeader(UiSettings);
	PrintData(Data, UiSettings);
	PrintFooter(UiSettings.LineWidth);
}

StData GetClint(string AccountNumber, vector<StData> vData)
{
	for (StData Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
			return Data;
	}
}
void DeleteClint()
{
	PrintDeleteClintScreen();

	string AccountNumber = ReadString("Enter Account Number : ");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);

	if (!IsClintExist(AccountNumber, vData, ClintsDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StData Data = GetClint(AccountNumber, vData);
	PrintClintInfo(Data);

	if (YesNoQuestion() == No)
		return;


	vData = DeleteClintFromVector(AccountNumber, vData);
	WriteToFile(vData, ClintsDataFilePath);

}

void PrintUpdateClintScreen()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t U P D A T E - C L I N T", UiSettings.LineWidth);

}

StData ReadNewData(string AccountNumber)
{
	StData Data;

	Data.AcountNumber = AccountNumber;

	cout << "Pin Code : ";
	getline(cin >> ws, Data.PinCode);

	cout << "Name : ";
	getline(cin, Data.Name);

	cout << "Phone : ";
	getline(cin, Data.Phone);

	cout << "Acount Balance : ";
	cin >> Data.AcountBalance;


	return Data;
}

vector<StData> UpdateClintFromVector(StData NewData, vector<StData> vData)
{
	for (StData& Data : vData)
	{
		if (Data.AcountNumber == NewData.AcountNumber)
		{
			Data = NewData;
			return vData;
		}
	}
}


void UpdateClint()
{
	PrintUpdateClintScreen();
	string AccountNumber = ReadString("Enter Account Number : ");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);

	if (!IsClintExist(AccountNumber, vData, ClintsDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StData Data = GetClint(AccountNumber, vData);
	PrintClintInfo(Data);

	if (YesNoQuestion() == No)
		return;

	Data = ReadNewData(AccountNumber);
	vData = UpdateClintFromVector(Data, vData);

	WriteToFile(vData, ClintsDataFilePath);

}

void PrintFindClintScreen()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t F I N D - C L I N T", UiSettings.LineWidth);

}


void FindClint()
{
	PrintFindClintScreen();
	string AccountNumber = ReadString("Enter Account Number : ");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);
	if (!IsClintExist(AccountNumber, vData, ClintsDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StData Data = GetClint(AccountNumber, vData);
	PrintClintInfo(Data);
}

void PrintDepositMenu()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t D E P O S I T", UiSettings.LineWidth);
}

int ReadNumber(string Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}


vector<StData> UpdateBalance(string AccountNumber, float NewBalance, vector<StData> vData)
{
	for (StData& Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
		{
			Data.AcountBalance = NewBalance;
			return vData;
		}
	}
}

void DepositMenu()
{
	PrintDepositMenu();
	string AccountNumber = ReadString("Enter Account Number : ");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);

	if (!IsClintExist(AccountNumber, vData, ClintsDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StData Data = GetClint(AccountNumber, vData);
	PrintClintInfo(Data);

	float DepositAmount = ReadNumber("Enter Deposit Amount : ");

	if (YesNoQuestion() == No)
		return;

	float NewBalance = DepositAmount + Data.AcountBalance;
	vData = UpdateBalance(AccountNumber, NewBalance, vData);

	WriteToFile(vData, ClintsDataFilePath);
}


float GetTotalBalance(vector<StData> vData)
{
	float TotalBalance = 0;

	for (StData Data : vData)
		TotalBalance += Data.AcountBalance;

	return TotalBalance;
}

void TotalBalanceMenu()
{
	system("cls");
	vector<StData> vData = ReadFromFile(ClintsDataFilePath);

	StUiSettings UiSettings;

	PrintLable(vData.size());

	PrintLine(UiSettings.LineWidth);

	cout << left;
	cout << "|" << setw(UiSettings.AcountNumberWidth) << "Acount Number";
	cout << "|" << setw(UiSettings.NameWidth) << "Clint Name";
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << "Balance";
	cout << '\n';

	PrintLine(UiSettings.LineWidth);

	for (StData Data : vData)
	{
		cout << "|" << setw(UiSettings.AcountNumberWidth) << Data.AcountNumber;
		cout << "|" << setw(UiSettings.NameWidth) << Data.Name;
		cout << "|" << setw(UiSettings.AcountBalanceWidth) << Data.AcountBalance << '\n';
	}

	PrintLine(UiSettings.LineWidth);

	cout << "\tTotal Balance : " << GetTotalBalance(vData) << "\n\n";
}

void PrintWithdrawMenu()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t W I T H D R A W", UiSettings.LineWidth);
}


void WithdrawMenu()
{
	PrintWithdrawMenu();
	vector<StData> vData = ReadFromFile(ClintsDataFilePath);
	string AccountNumber = ReadString("Enter Account Number : ");

	if (!IsClintExist(AccountNumber, vData, ClintsDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StData Data = GetClint(AccountNumber, vData);
	PrintClintInfo(Data);

	float WithdrawAmount = ReadNumber("Enter Withdraw Amount : ");

	if (WithdrawAmount > Data.AcountBalance)
	{
		cout << "Withdraw Amount Is Bigger than Your Balance\n";
		return;
	}

	if (YesNoQuestion() == No)
		return;

	float NewBalance = Data.AcountBalance - WithdrawAmount;
	vData = UpdateBalance(AccountNumber, NewBalance, vData);
	WriteToFile(vData, ClintsDataFilePath);
}

void PerformMainMenuChoice(EnTransactionMenu Choice)
{
	switch (Choice)
	{
	case Deposit:
		DepositMenu();
		break;
	case Withdraw:
		WithdrawMenu();
		break;
	case TotalBalance:
		TotalBalanceMenu();
		break;
	case MainMenu:
		return;
	}
	BackToTransactionsMenu();
}

void TransactionMenu()
{

	vector<string> Choices
	{
		"Deposit",
		"Withdraw",
		"Total Balance",
		"Main Menu"
	};

	PrintMenuWithChoices(Choices, " T R A N S A C T I O N S");

	EnTransactionMenu Choice = static_cast<EnTransactionMenu> (ReadNumberInRange("Chose From [1, 4] : ", 1, 4));

	PerformMainMenuChoice(Choice);
}


void BackToTransactionsMenu()
{
	cout << "Enter Any Key To Back To Transactions Menu...";
	system("pause>0");
	TransactionMenu();

}
StUser UserRecordToData(string String, string Separator = "#//#")
{
	StUser Data;

	vector<string> SparatedString = Split(String, Separator);

	Data.UserName = SparatedString[0];
	Data.Password = SparatedString[1];
	Data.Permissions = stoi(SparatedString[2]);

	return Data;
}

vector<StUser> ReadUsersFile(string FilePath)
{
	vector<StUser> vData;

	fstream File;
	File.open(FilePath, ios::in);

	if (File.is_open())
	{
		string Line;
		while (getline(File, Line))
			vData.push_back(UserRecordToData(Line));
	}

	return vData;
}

void ListUsersScreen()
{
	system("cls");

	vector<StUser> vData = ReadUsersFile(UsersDataFilePath);

	StUiSettings UiSettings;

	PrintLable(vData.size());

	PrintLine(UiSettings.LineWidth);

	cout << left;
	cout << "|" << setw(UiSettings.AcountNumberWidth) << "User Name";
	cout << "|" << setw(UiSettings.NameWidth) << "Password";
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << "Permissions";
	cout << '\n';

	PrintLine(UiSettings.LineWidth);

	for (StUser Data : vData)
	{
		cout << "|" << setw(UiSettings.AcountNumberWidth) << Data.UserName;
		cout << "|" << setw(UiSettings.NameWidth) << Data.Password;
		cout << "|" << setw(UiSettings.AcountBalanceWidth) << Data.Permissions << '\n';
	}

	PrintLine(UiSettings.LineWidth);


}

int ReadPermission()
{
	int Permissios = 0;

	if (YesNoQuestion("Give Him Full Accsess [Y, n]: ") == Yes)
		return eAllPermissios;


	if (YesNoQuestion("Give Him Accsess On > Show Clint List < [Y, n]: ") == Yes)
		Permissios += eShowClintList;

	if (YesNoQuestion("Give Him Accsess On > Add New Clint < [Y, n]: ") == Yes)
		Permissios += eAddNewClint;

	if (YesNoQuestion("Give Him Accsess On > Delete Clint < [Y, n]: ") == Yes)
		Permissios += eDeleteClint;

	if (YesNoQuestion("Give Him Accsess On > Update Clint < [Y, n]: ") == Yes)
		Permissios += eUpdateClint;

	if (YesNoQuestion("Give Him Accsess On > Find Clint < [Y, n]: ") == Yes)
		Permissios += eFindClint;

	if (YesNoQuestion("Give Him Accsess On > Transactions < [Y, n]: ") == Yes)
		Permissios += eTransaction;

	if (YesNoQuestion("Give Him Accsess On > Manage Users < [Y, n]: ") == Yes)
		Permissios += eManageUsers;

	return Permissios;

}

StUser ReadUser()
{
	StUser Data;

	cout << "User Name : ";
	getline(cin >> ws, Data.UserName);

	cout << "Password : ";
	getline(cin, Data.Password);

	Data.Permissions = ReadPermission();

	return Data;
}

vector<StUser> ReadUsers()
{
	vector<StUser> vClints;

	do
	{
		vClints.push_back(ReadUser());
	} while (YesNoQuestion("Wanna Add More Users ? [Y, n]") == Yes);

	return vClints;
}

string DataUsersToRecord(StUser Data, string Separator = "#//#")
{
	string Record;

	Record += Data.UserName + Separator;
	Record += Data.Password + Separator;
	Record += to_string(Data.Permissions);

	return Record;
}

EnStatus AddUsersToFile(vector<StUser> vData, string FilePath)
{
	fstream File;

	File.open(FilePath, ios::out | ios::app);

	if (!File.is_open())
		Fail;

	for (StUser Data : vData)
		File << DataUsersToRecord(Data) + '\n';

	File.close();

	return Success;
}

void AddNewUserScreen()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t A D D - N E W - U S E R S", UiSettings.LineWidth);

	vector<StUser> vClints = ReadUsers();
	AddUsersToFile(vClints, UsersDataFilePath);

}
bool IsUserExist(string UserName, vector<StUser> vData, string FilePath)
{

	for (StUser Data : vData)
	{
		if (Data.UserName == UserName)
			return true;
	}
	return false;

}

StUser GetUser(string UserName, vector<StUser> vData)
{
	for (StUser Data : vData)
	{
		if (Data.UserName == UserName)
			return Data;
	}
}

void PrintUserInfo(StUser Data)
{
	system("cls");

	StUiSettings UiSettings;

	PrintLine(UiSettings.LineWidth);

	cout << left;
	cout << "|" << setw(UiSettings.AcountNumberWidth) << "User Name";
	cout << "|" << setw(UiSettings.NameWidth) << "Password";
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << "Permissions";
	cout << '\n';

	PrintLine(UiSettings.LineWidth);

	cout << "|" << setw(UiSettings.AcountNumberWidth) << Data.UserName;
	cout << "|" << setw(UiSettings.NameWidth) << Data.Password;
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << Data.Permissions << '\n';

	PrintLine(UiSettings.LineWidth);
}


vector<StUser> DeleteUserFromVector(string UserName, vector<StUser> vData)
{
	vector<StUser>::iterator Iterator = vData.begin();

	for (Iterator; Iterator != vData.end(); Iterator++)
	{
		StUser Data = *Iterator;

		if (Data.UserName == UserName)
		{
			vData.erase(Iterator);
			return vData;
		}
	}
}

EnStatus WriteUsersToFile(vector<StUser> vData, string FilePath)
{
	fstream File;

	File.open(FilePath, ios::out);

	if (!File.is_open())
		Fail;

	for (StUser Data : vData)
		File << DataUsersToRecord(Data) + '\n';

	File.close();

	return Success;
}

void DeleteUser()
{
	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t D E L E T E - U S E R S", UiSettings.LineWidth);

	string UserName = ReadString("Enter User Name : ");

	vector<StUser> vData = ReadUsersFile(UsersDataFilePath);

	if (!IsUserExist(UserName, vData, UsersDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StUser Data = GetUser(UserName, vData);
	PrintUserInfo(Data);

	if (YesNoQuestion() == No)
		return;


	vData = DeleteUserFromVector(UserName, vData);
	WriteUsersToFile(vData, UsersDataFilePath);

}
StUser ReadNewUserData(string UserName)
{
	StUser Data;

	Data.UserName = UserName;

	cout << "Password : ";
	getline(cin >> ws, Data.Password);

	Data.Permissions = ReadPermission();

	return Data;
}
vector<StUser> UpdateUserFromVector(StUser NewData, vector<StUser> vData)
{
	for (StUser& Data : vData)
	{
		if (Data.UserName == NewData.UserName)
		{
			Data = NewData;
			return vData;
		}
	}
}


void UpdateUser()
{
	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t U P D A T E - U S E R S", UiSettings.LineWidth);

	string UserName = ReadString("Enter User Name : ");

	vector<StUser> vData = ReadUsersFile(UsersDataFilePath);

	if (!IsUserExist(UserName, vData, UsersDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StUser Data = GetUser(UserName, vData);
	PrintUserInfo(Data);

	if (YesNoQuestion() == No)
		return;

	Data = ReadNewUserData(UserName);
	vData = UpdateUserFromVector(Data, vData);

	WriteUsersToFile(vData, UsersDataFilePath);

}
void FindUser()
{
	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t F I N D - U S E R S", UiSettings.LineWidth);

	string UserName = ReadString("Enter User Name : ");

	vector<StUser> vData = ReadUsersFile(UsersDataFilePath);

	if (!IsUserExist(UserName, vData, UsersDataFilePath))
	{
		cout << "Not Found\n";
		return;
	}

	StUser Data = GetUser(UserName, vData);
	PrintUserInfo(Data);
}

void PerformMangageUsersChoice(EnManageUsersMenu Choice)
{
	system("cls");
	switch (Choice)
	{
	case eListUsers:
		ListUsersScreen();
		break;
	case eAdd:
		AddNewUserScreen();
		break;
	case eDelete:
		DeleteUser();
		break;

	case eUpdate:
		UpdateUser();
		break;

	case eFind:
		FindUser();
		break;
	case eMainMenu:
		return;
	}
	BackToMangageUsersMenu();
}

void MangageUsersMenu()
{

	vector<string> Choices
	{
		"List Users",
		"Add New Users",
		"Delete User",
		"Update User",
		"Find User",
		"Main Menu"
	};

	PrintMenuWithChoices(Choices, " M A N A G E - U S E R S");

	short ChoicesCount = Choices.size();
	EnManageUsersMenu Choice = static_cast<EnManageUsersMenu> (ReadNumberInRange("Chose From [1, " + to_string(ChoicesCount) + "] : ", 1, ChoicesCount));

	PerformMangageUsersChoice(Choice);
}


void BackToMangageUsersMenu()
{
	cout << "Enter Any Key To Back To Mangage Users Menu...";
	system("pause>0");
	system("cls");
	MangageUsersMenu();

}


void ClintsListScreen()
{
	system("cls");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);

	StUiSettings UiSettings;

	PrintLable(vData.size());

	PrintLine(UiSettings.LineWidth);

	cout << left;
	cout << "|" << setw(UiSettings.AcountNumberWidth) << "Acount Number";
	cout << "|" << setw(UiSettings.NameWidth) << "Clint Name";
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << "Balance";
	cout << '\n';

	PrintLine(UiSettings.LineWidth);

	for (StData Data : vData)
	{
		cout << "|" << setw(UiSettings.AcountNumberWidth) << Data.AcountNumber;
		cout << "|" << setw(UiSettings.NameWidth) << Data.Name;
		cout << "|" << setw(UiSettings.AcountBalanceWidth) << Data.AcountBalance << '\n';
	}

	PrintLine(UiSettings.LineWidth);

	cout << "\tTotal Balance : " << GetTotalBalance(vData) << "\n\n";

}



void PerformMainMenuChoice(EnMainMenu Choice)
{
	system("cls");

	switch (Choice)
	{
	case Show:
		ClintsList();
		break;

	case Add:
		AddNewClints();
		break;

	case Delete:
		DeleteClint();
		break;

	case Update:
		UpdateClint();
		break;

	case Find:
		FindClint();
		break;

	case Transaction:
		TransactionMenu();
		break;

	case ManageUsers:
		MangageUsersMenu();
		break;

	case Logout:
		return;
	}

	BackToMainMenu();

}

void MainMenuScreen()
{

	vector<string> Choices
	{
		"Show Clint List",
		"Add New Clint",
		"Delete Clint",
		"Update Clint",
		"Find Clint",
		"Transactions",
		"Manage Users",
		"Logout"
	};

	PrintMenuWithChoices(Choices, " M A I N - M E N U");


	EnMainMenu Choice = static_cast<EnMainMenu> (ReadNumberInRange("Chose From [1, 8] : ", 1, 8));

	PerformMainMenuChoice(Choice);
}

void BackToMainMenu()
{
	cout << "Enter Any Key To Back To Main Menu...";
	system("pause>0");

	system("cls");
	MainMenuScreen();

}


int main()
{
	MainMenuScreen();
}



