
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

string ToLower(string String)
{
	for (size_t i = 0; i < String.length(); i++)
	{
		String[i] = tolower(String[i]);
	}
	return String;
}


string Replace(string WordToReplace, string ReplaceTo, string String, bool MatchCase = true)
{

	int Position = 0;
	int WordToReplaceLength = WordToReplace.length();

	if (!MatchCase)
	{
		String = ToLower(String);
		WordToReplace = ToLower(WordToReplace);
	}

	while ((Position = String.find(WordToReplace)) != string::npos)
	{

		String.erase(Position, WordToReplaceLength);
		String.insert(Position, ReplaceTo);
	}
	return String;
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

StDate stringToDate(string DateString)
{
	vector<string> SparatedString = Split(DateString, "/");

	StDate Date;

	Date.Day = stoi(SparatedString[0]);
	Date.Month = stoi(SparatedString[1]);
	Date.Year = stoi(SparatedString[2]);

	return Date;
}

string FormatDate(StDate Date, string Format = "dd/mm/yy")
{
	Format = Replace("dd", to_string(Date.Day), Format);
	Format = Replace("mm", to_string(Date.Month), Format);
	Format = Replace("yy", to_string(Date.Year), Format);

	return Format;
}

int main()
{

	StDate Date = stringToDate("31/12/2022");

	cout << FormatDate(Date, "dd :: mm :: yy");
}


