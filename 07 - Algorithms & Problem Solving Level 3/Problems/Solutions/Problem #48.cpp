
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>


using namespace std;

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



void PrintLine(int Width)
{
	for (size_t i = 0; i < Width; i++)
		cout << '-';
	cout << '\n';
}

void PrintLable(int ClintCount)
{
	cout << "\t\t\tClint List [" << ClintCount << "] Clint(s)\n";
}

void PrintHeader( StUiSettings UiSettings)
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

	cout << "|" << setw(UiSettings.AcountNumberWidth) << Data.AcountNumber ;
	cout << "|" << setw(UiSettings.PinCodeWidth) << Data.PinCode;
	cout << "|" << setw(UiSettings.NameWidth) << Data.Name ;
	cout << "|" << setw(UiSettings.PhoneWidth) << Data.Phone ;
	cout << "|" << setw(UiSettings.AcountBalanceWidth) << Data.AcountBalance  << '\n';
}

void PrintFooter(int Width)
{
	PrintLine(Width);

}

void PrintVData(vector<StData> vData, StUiSettings UiSettings)
{
	for (StData Data : vData)
		PrintData(Data, UiSettings);
}

int main()
{
	StUiSettings UiSettings;

	string FilePath = "Data.txt";

	vector<StData> vData = ReadFileData(FilePath);

	PrintLable(vData.size());
	PrintHeader(UiSettings);
	PrintVData(vData, UiSettings);
	PrintFooter(UiSettings.LineWidth);
}


