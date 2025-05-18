
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


int CountVowels(string String)
{
	int Counter = 0;

	for (size_t i = 0; i < String.length(); i++)
	{
		if (IsVowel(String[i]))
			Counter++;
	}
	return Counter;
}

int main()
{

	cout << CountVowels("a dadad jfgkjv");

}


