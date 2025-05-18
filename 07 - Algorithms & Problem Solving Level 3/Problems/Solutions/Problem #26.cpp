
#include <iostream>

using namespace std;

string LowerString(string String)
{

	for (size_t i = 0; i < String.length(); i++)
	{
		String[i] = tolower(String[i]);
	}
	return String;
}


string UpperString(string String)
{

	for (size_t i = 0; i < String.length(); i++)
	{
		String[i] = toupper(String[i]);
	}
	return String;
}


int main()
{
	cout << LowerString("Abdo Waffa") << endl;
	cout << UpperString("Abdo Waffa") << endl;

}

