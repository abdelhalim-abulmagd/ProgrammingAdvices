
#include <iostream>

using namespace std;


string Replace(string WordToReplace, string ReplaceTo, string String)
{

	int Position = 0;
	int WordToReplaceLength = WordToReplace.length();


	while ((Position = String.find(WordToReplace)) != string::npos)
	{
		String.erase(Position, WordToReplaceLength);
		String.insert(Position, ReplaceTo);
	}
	return String;
}

string ReplaceUsingBuiltIn(string WordToReplace, string ReplaceTo, string String)
{

	int Position = 0;
	int WordToReplaceLength = WordToReplace.length();


	while ((Position = String.find(WordToReplace)) != string::npos)
	{
		String.replace(Position, WordToReplaceLength, ReplaceTo);
	}
	return String;
}

int main()
{
	string String = "Abdo Waffa Abdo Waffa Abdo Waffa Abdo Waffa";


	cout << Replace("Waffa", "Ali", String) << endl;
	cout << ReplaceUsingBuiltIn("Waffa", "Ali", String) << endl;



}


