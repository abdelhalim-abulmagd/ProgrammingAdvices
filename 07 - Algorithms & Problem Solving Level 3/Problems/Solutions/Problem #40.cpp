
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

string JoinString(string WordsArray[], int ArrayLength, string Seperator = " ")
{
	string Result = "";

	for (size_t i = 0; i < ArrayLength; i++)
	{
		Result += WordsArray[i] + Seperator;

	}
	return Result.substr(0, Result.length() - Seperator.length());
}

int main()
{
	vector<string> Words{ "Abdo", "Waffa" };

	string WordsArray[2] { "Ali", "Noha" };


	cout << JoinString(Words) << endl;
	cout << JoinString(WordsArray, 2) << endl;
}


