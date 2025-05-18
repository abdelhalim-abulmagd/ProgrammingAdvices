
#include <iostream>

using namespace std;


// "ABDO" -> "abdo"

string ToLower(string String)
{
	for (size_t i = 0; i < String.length(); i++)
	{
		String[i] = tolower(String[i]);
	}
	return String;
}


string Replace(string WordToReplace, string ReplaceTo, string String, bool MatchCase = true )
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

int main()
{
	string String = "Abdo Waffa Abdo Waffa Abdo Waffa Abdo Waffa";


	cout << Replace("Waffa", "Ali", String, 1) << endl;
	cout << Replace("waffa", "Ali", String, 0 ) << endl;



}


