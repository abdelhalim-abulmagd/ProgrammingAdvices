
#include <iostream>

using namespace std;


bool IsPuncuations(char Character)
{
	switch (Character)
	{
	case ';':
		return true;
	case '.':
		return true;
	case '\'':
		return true;
	case '"':
		return true;
	default:
		return false;
	}
}


string RemovePuncuations(string String )
{

	for (size_t i = 0; i < String.length(); i++)
	{
		if (IsPuncuations(String[i]))
			String.replace(i, 1, "");
	}
	return String;
}

int main()
{
	string String = "Abdo 'Waffa Abdo; Waffa. Abdo Waffa\" Abdo Waffa";


	cout << RemovePuncuations(String) << endl;



}


