
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

int main()
{

	cout << IsVowel('A');

}


