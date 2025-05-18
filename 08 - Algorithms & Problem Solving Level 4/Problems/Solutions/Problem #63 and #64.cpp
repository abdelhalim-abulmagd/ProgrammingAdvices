
#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct StDate
{
	short Day;
	short Month;
	short Year;
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

StDate stringToDate(string DateString)
{
	vector<string> SparatedString = Split(DateString, "/");

	StDate Date;

	Date.Day = stoi(SparatedString[0]);
	Date.Month = stoi(SparatedString[1]);
	Date.Year = stoi(SparatedString[2]);

	return Date;
}


string DateToString(StDate Date, string Separator = "/")
{
	return to_string(Date.Day) + Separator + to_string(Date.Month) + Separator + to_string(Date.Year );
}

int main()
{
	
	string DateString = "31/3/2022";

	StDate Date = stringToDate(DateString);


	cout << Date.Day << ":" << Date.Month << ":" << Date.Year << endl;
	cout << DateToString(Date);
}


