#include <iostream>
#include <vector>
#include <string>
#include <fstream>


using namespace std;
const string ClintsDataFilePath = "Clints.txt";
enum EnMainMenu { QuickWithDraw = 1, NormalWithDraw = 2, Deposit = 3, Balance = 4, Logout = 5 };
enum EnAnwer { No, Yes };
enum EnStatus { Fail, Success };

void LoginScreen();
void MainMenuScreen();

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

StData CurrentClint;

void PrintLine(int Width)
{
	for (size_t i = 0; i < Width; i++)
		cout << '-';
	cout << '\n';
}

void BackToMainMenu()
{
	cout << "Enter Any Key To Back To Main Menu...";
	system("pause>0");

	//system("cls");
	MainMenuScreen();

}



void PrintHeader(string Msg, int Width)
{

	PrintLine(Width);

	cout << Msg << "\n";

	PrintLine(Width);

}


StData GetClint(string AccountNumber, vector<StData> vData)
{
	for (StData Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
			return Data;
	}
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


bool IsClintExist(string AccountNumber, string PinCode, vector<StData> vData)
{

	for (StData Data : vData)
	{
		if (Data.AcountNumber == AccountNumber && Data.PinCode == PinCode)
			return true;
	}
	return false;

}


string ReadString(string Msg)
{
	string AccountNumber;
	cout << Msg;
	getline(cin >> ws, AccountNumber);
	return AccountNumber;
}

string LoginLogic(vector<StData> vData)
{
	string AccountNumber;
	string PinCode;

	bool LoginSuccess = false;

	do
	{
		AccountNumber = ReadString("Enter Account Number : ");
		PinCode = ReadString("Enter Pin Code : ");

		LoginSuccess = IsClintExist(AccountNumber, PinCode, vData);

		if (!LoginSuccess)
			cout << "Wrong User Account  Number Or Pin Code\n";

	} while (!LoginSuccess);

	return AccountNumber;
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

void BalanceScreen()
{

	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t B A L A N C E", UiSettings.LineWidth);
	cout << CurrentClint.AcountBalance << endl;
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

vector<StData> UpdateBalance(string AccountNumber, float NewBalance, vector<StData> vData)
{
	for (StData& Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
		{
			Data.AcountBalance = NewBalance;
			CurrentClint = Data;
			return vData;
		}
	}
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

void WithDrawLogic(float WithdrawAmount, vector<StData> vData)
{


	if (WithdrawAmount > CurrentClint.AcountBalance)
	{
		cout << "Withdraw Amount Is Bigger than Your Balance\n";
		return;
	}

	if (YesNoQuestion() == No)
		return;

	float NewBalance = CurrentClint.AcountBalance - WithdrawAmount;
	vData = UpdateBalance(CurrentClint.AcountNumber, NewBalance, vData);
	WriteToFile(vData, ClintsDataFilePath);

}


void QuickWithDrawScreen()
{

	system("cls");
	vector<string> Choices
	{
		"50",
		"100",
		"200",
		"600",
		"1000"
	};

	PrintMenuWithChoices(Choices, "Q U I C K - W I T H D R A W");

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);
	cout << "Current Balance : "<< CurrentClint.AcountBalance << '\n';

	short WithdrawAmount = ReadNumberInRange("Chose From [1, 5] : ", 1, 5);

	if (WithdrawAmount == 1)
		WithdrawAmount = 50;
	else if (WithdrawAmount == 2)
		WithdrawAmount = 100;
	else if (WithdrawAmount == 3)
		WithdrawAmount = 200;
	else if (WithdrawAmount == 4)
		WithdrawAmount = 600;
	else if (WithdrawAmount == 5)
		WithdrawAmount = 1000;

	WithDrawLogic(WithdrawAmount, vData);


}
float ReadNumber(string Msg)
{
	float Number;
	cout << Msg;
	cin >> Number;
	return Number;
}


void NormalWithDrawScreen()
{
	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t N O R M A L - W I T H D R A W", UiSettings.LineWidth);

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);
	cout << "Current Balance : " << CurrentClint.AcountBalance << '\n';
	float WithdrawAmount = ReadNumber("Enter Withdraw Amount : ");

	WithDrawLogic(WithdrawAmount, vData);
}

void DepositScreen()
{
	vector<StData> vData = ReadFromFile(ClintsDataFilePath);
	system("cls");

	StUiSettings UiSettings;
	PrintHeader("\t\t D E P O S I T", UiSettings.LineWidth);

	cout << "Current Balance : " << CurrentClint.AcountBalance << '\n';

	float DepositAmount = ReadNumber("Enter Deposit Amount : ");

	if (YesNoQuestion() == No)
		return;

	float NewBalance = CurrentClint.AcountBalance + DepositAmount;
	vData = UpdateBalance(CurrentClint.AcountNumber, NewBalance, vData);
	WriteToFile(vData, ClintsDataFilePath);

}

void PerformMainMenuChoice(EnMainMenu Choice)
{
	switch (Choice)
	{
	case QuickWithDraw:
		QuickWithDrawScreen();
		break;
	case NormalWithDraw:
		NormalWithDrawScreen();
		break;
	case Deposit:
		DepositScreen();
		break;
	case Balance:
		BalanceScreen();
		break;
	case Logout:
		LoginScreen();
		break;

	}
	BackToMainMenu();
}


void MainMenuScreen()
{

	system("cls");
	vector<string> Choices
	{
		"Quick Withdraw",
		"Normal Withdraw",
		"Deposit",
		"Balance",
		"Logout"
	};

	PrintMenuWithChoices(Choices, " M A I N - M E N U");


	EnMainMenu Choice = static_cast<EnMainMenu> (ReadNumberInRange("Chose From [1, 5] : ", 1, 5));

	PerformMainMenuChoice(Choice);
}


void LoginScreen()
{
	system("cls");
	StUiSettings UiSettings;
	PrintHeader("\t\t L O G I N", UiSettings.LineWidth);

	vector<StData> vData = ReadFromFile(ClintsDataFilePath);


	string AccountNumber = LoginLogic(vData);
	CurrentClint = GetClint(AccountNumber, vData);

	MainMenuScreen();
}


int main()
{
	LoginScreen();
}
