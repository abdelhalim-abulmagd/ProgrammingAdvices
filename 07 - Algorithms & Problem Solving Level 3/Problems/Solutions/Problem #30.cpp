
#include <iostream>

using namespace std;



int CountCharacterInString(char Character, string String)
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

int main()
{

	string String = ("aa  AAA m m m A  aaa");
	char CharacterToCount = 'A';

	cout << CountCharacterInString(CharacterToCount, String) << endl;

}


