
#include <iostream>
#include <vector>

using namespace std;

/*
* First Method

void PrintFirstWord(string String)
{
	string word = "";


	for (size_t i = 0; i < String.length(); i++)
	{
		if (String[i] != ' ')
		{
			word += String[i];
		}
		else if( !word.empty() )
		{
			cout << word << endl;
			word = "";
		}
		
	}

	if(!word.empty())
		cout << word << endl;
}
*/

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

	if(String != "")
		Words.push_back(String);

	return Words;
}

void Print(vector<string> Words)
{
	for (string Word : Words)
		cout << Word << endl;

	cout << "Done";
}

int main()
{
	//PrintFirstWord("a dadad jfgkjv");

	vector<string> Words = Split("          a         dadad          jfgkjv             s");
	Print(Words);

}


