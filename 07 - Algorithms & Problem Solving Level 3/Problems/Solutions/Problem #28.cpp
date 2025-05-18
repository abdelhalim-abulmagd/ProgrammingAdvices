
#include <iostream>

using namespace std;


char InvertCharacterCase(char Character)
{

	return islower(Character) ? toupper(Character) : tolower(Character);

}


string InvertStringCase(string String)
{
	for (size_t i = 0; i < String.length(); i++)
	{
		String[i] = InvertCharacterCase(String[i]);
	}
	return String;
}

int main()
{
	cout << InvertStringCase("aaaaa") << endl;
	cout << InvertStringCase("AAAAA") << endl;

}


