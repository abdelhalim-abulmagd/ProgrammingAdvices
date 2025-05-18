
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

enum EnAnwer { No, Yes };
enum EnStatus { Fail, Success };

using namespace std;

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
	string DefultMsg = "Do You Want Add More? [Y, n] : ";

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
	} while (YesNoQuestion()  == Yes);

	return vClints;
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
	{
		File << DataToRecord(Data) + '\n';
	}

	File.close();

	return Success;
}


int main()
{

	string FilePath = "Data.txt";

	vector<StData> vData = ReadClints();

	AddToFile(vData, FilePath);
}


