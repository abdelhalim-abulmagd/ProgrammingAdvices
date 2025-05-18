
#include <iostream>
#include <vector>

using namespace std;

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

void Print(vector<string> Words)
{
	for (string Word : Words)
		cout << Word << endl;
}

int main()
{
	string String = "Abdo Waffa";

	vector<string> Words = Split(String);
	Print(Words);

}


