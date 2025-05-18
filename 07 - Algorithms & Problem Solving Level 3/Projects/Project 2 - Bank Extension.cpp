
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

void BackToMainMenu();
void BackToTransactionsMenu();

const string ClintsDataFilePath = "Data.txt";

enum EnAnwer { No, Yes };
enum EnStatus { Fail, Success };
enum EnMainMenu { Show = 1, Add = 2, Delete = 3, Update = 4, Find = 5, Transaction = 6, Exit = 7 };
enum EnTransactionMenu { Deposit = 1, Withdraw = 2, TotalBalance = 3, MainMenu = 4,};

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

void PrintMainMenuScreen(int Width)
{
	PrintHeader("\t\t M A I N - M E N U", Width);

	vector<string> Choices
	{
		"Show Clint List",
		"Add New Clint",
		"Delete Clint",
		"Update Clint",
		"Find Clint",
		"Transactions",
		"Exit"
	};

	PrintScreenChoice(Choices);

	PrintLine(Width);
}

bool IsInRange(int Number, int From, int To)
{
	return (Number >= From && Number <= To);
}

short ReadNumberInRange(string Msg, int From = 1, int To = 7)
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

void PrintLable(int ClintCount)
{
	cout << "\t\t\tClint List [" << ClintCount << "] Clint(s)\n";
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

void PrintTransactionMenu()
{
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t T R A N S A C T I O N S", UiSettings.LineWidth);

	vector<string> Choices
	{
		"Deposit",
		"Withdraw",
		"Total Balance",
		"Main Menu"
	};

	PrintScreenChoice(Choices);

	PrintLine(UiSettings.LineWidth);
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
	PrintTransactionMenu();

	EnTransactionMenu Choice = static_cast<EnTransactionMenu> (ReadNumberInRange("Chose From [1, 4] : ", 1, 4));

	PerformMainMenuChoice(Choice);
}


void BackToTransactionsMenu()
{
	cout << "Enter Any Key To Back To Transactions Menu...";
	system("pause>0");
	TransactionMenu();

}


void PerformMainMenuChoice(EnMainMenu Choice)
{
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

	case Exit:
		return;
	}

	BackToMainMenu();

}

void MainMenuScreen()
{
	system("cls");

	StUiSettings UiSettings;

	UiSettings.LineWidth = 50;


	PrintMainMenuScreen(UiSettings.LineWidth);

	EnMainMenu Choice = static_cast<EnMainMenu> (ReadNumberInRange("Chose From [1, 7] : "));

	PerformMainMenuChoice(Choice);
}

void BackToMainMenu()
{
	cout << "Enter Any Key To Back To Main Menu...";
	system("pause>0");
	MainMenuScreen();

}


int main()
{
	MainMenuScreen();
}



