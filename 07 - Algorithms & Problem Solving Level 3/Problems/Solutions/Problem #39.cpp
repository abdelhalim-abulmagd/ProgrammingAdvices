
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

int main()
{
	vector<string> Words{ "Abdo", "Waffa" };

	cout << JoinString(Words);
}


