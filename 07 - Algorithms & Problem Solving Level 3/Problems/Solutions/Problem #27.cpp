
#include <iostream>

using namespace std;


char InvertCharacterCase(char Character)
{

	return islower(Character) ? toupper(Character) : tolower(Character);

}


int main()
{
	cout << InvertCharacterCase('a') << endl;
	cout << InvertCharacterCase('A') << endl;

}

