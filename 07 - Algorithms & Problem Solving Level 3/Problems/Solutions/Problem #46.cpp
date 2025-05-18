
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

void Print(StData Data)
{
	cout << Data.AcountNumber << endl;
	cout << Data.PinCode << endl;
	cout << Data.Name << endl;
	cout << Data.Phone << endl;
	cout << Data.AcountBalance << endl;
}


int main()
{
	string Record = "A150#//#1234#//#Abdo#//#01008640565#//#5000.000000";

	StData Data = RecordToData(Record);

	Print(Data);


}


