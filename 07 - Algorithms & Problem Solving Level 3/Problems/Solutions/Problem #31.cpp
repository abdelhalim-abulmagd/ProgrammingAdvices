
#include <iostream>

using namespace std;

enum EnStatus { NotCaseSensitive, CaseSensitive };

string LowerString(string String)
{

	for (size_t i = 0; i < String.length(); i++)
	{
		String[i] = tolower(String[i]);
	}
	return String;
}

int CountCharacter(char Character, string String)
{
	int Counter = 0;

	int position  = 0;

	while ((position = String.find(Character)) != string::npos)
	{
		Counter++;
		String = String.substr(++position, String.length());
	}

	return Counter;
}

int CountCharacterInString(char Character, string String, EnStatus Case = EnStatus::NotCaseSensitive)
{
	switch (Case)
	{
	case NotCaseSensitive:
		return CountCharacter(Character, String);
	
	case CaseSensitive:
		return CountCharacter(tolower(Character), LowerString(String));
	}
}

int main()
{

	string String = ("aa  AAA m m m A MM aaa");
	char CharacterToCount = 'm';

	cout << CountCharacterInString(CharacterToCount, String, CaseSensitive) << endl;

}


