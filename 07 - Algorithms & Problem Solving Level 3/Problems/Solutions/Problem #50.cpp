
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>


using namespace std;
enum EnAnwer { No, Yes };
enum EnStatus { Fail, Success };

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


EnAnwer YesNoQuestion(string Msg = "")
{
	string DefultMsg = " [Y, n] : ";

	Msg = Msg == "" ? DefultMsg : Msg + DefultMsg;

	char Answer;
	cout << Msg;
	cin >> Answer;

	return tolower(Answer) == 'y' ? Yes : No;
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

vector<StData> ReadFileData(string FilePath)
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



bool IsClintExist(string AccountNumber, string FilePath)
{
	vector<StData> vData = ReadFileData(FilePath);

	for (StData Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
			return true;
	}

	return false;

}

StData GetClintFromFile(string AccountNumber, string FilePath)
{
	vector<StData> vData = ReadFileData(FilePath);

	for (StData Data : vData)
	{
		if (Data.AcountNumber == AccountNumber)
			return Data;
	}
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

void PrintLable(int ClintCount)
{
	cout << "\t\t\tClint List [" << ClintCount << "] Clint(s)\n";
}
void PrintLine(int Width)
{
	for (size_t i = 0; i < Width; i++)
		cout << '-';
	cout << '\n';
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

void PrintFooter(int Width)
{
	PrintLine(Width);

}

void PrintClintInfo(StData Data, StUiSettings UiSettings)
{
	PrintHeader(UiSettings);
	PrintData(Data, UiSettings);
	PrintFooter(UiSettings.LineWidth);
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



EnStatus WriteFile(vector<StData> vData, string FilePath)
{
	fstream File;

	File.open(FilePath, ios::out );

	if (!File.is_open())
		Fail;

	for (StData Data : vData)
	{
		if (Data.AcountNumber != "")
			File << DataToRecord(Data) + '\n';
	}

	File.close();

	return Success;
}


EnStatus DeleteClint(string AcountNumber, vector<StData> vData, string FilePath)
{
	for (StData &Data : vData)
	{
		if (Data.AcountNumber == AcountNumber)
		{
			Data.AcountNumber = "";
			return WriteFile(vData, FilePath);
		}
	}

	return Fail;

}


int main()
{
	StUiSettings UiSettings;

	string FilePath = "Data.txt";
	string AccountToFind("a400");

	if (!IsClintExist(AccountToFind, FilePath))
	{
		cout << "Dont Find";
		return 0;
	}

	StData Data = GetClintFromFile(AccountToFind, FilePath);
	PrintClintInfo(Data, UiSettings);


	if (YesNoQuestion("Are U Sure ? ") == Yes)
		if (DeleteClint(AccountToFind, ReadFileData(FilePath), FilePath) == Success)
			cout << "Success";
		else
			cout << "Fail";

}


