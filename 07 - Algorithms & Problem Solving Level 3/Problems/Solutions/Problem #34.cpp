
#include <iostream>

using namespace std;


bool IsVowel(char Character)
{
	switch (tolower(Character))
	{
	case 'a':
		return true;
	case 'e':
		return true;
	case 'i':
		return true;
	case 'o':
		return true;
	case 'u':
		return true;

	default:
		return false;
	}
}


void PrintVowelsInString(string String)
{

	for (size_t i = 0; i < String.length(); i++)
	{
		if (IsVowel(String[i]))
			cout << String[i] <<  " - ";
	}

}

int main()
{

	PrintVowelsInString("a dadad jfgkjv");

}


