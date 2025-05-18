
#include <iostream>
#include <vector>

using namespace std;


string JoinString(vector<string> Words, string Seperator = " ")
{
	string Result = "";

	for (string Word : Words)
	{
		Result += Word + Seperator;
	}
	return Result.substr(0, Result.length() - Seperator.length());
}

vector<string> Split(string String, string Seperator = " ")
{
	vector<string> Words;

	int Position = 0;

	while ((Position = String.find(Seperator)) != string::npos)
	{
		string Word = String.substr(0, Position);

		if (Word != "")
			Words.push_back(Word);

		String.erase(0, Position + Seperator.length());
	}

	if (String != "")
		Words.push_back(String);

	return Words;
}

string ReverceString(string String)
{
	vector<string> vWords = Split(String);
	vector<string> vRevercedWords ;

	for (string Word : vWords)
	{
		vRevercedWords.insert(vRevercedWords.begin(), Word);
	}


	return JoinString(vRevercedWords);
}

int main()
{
	string String = "Abdo Waffa";

	cout << ReverceString(String);



}


