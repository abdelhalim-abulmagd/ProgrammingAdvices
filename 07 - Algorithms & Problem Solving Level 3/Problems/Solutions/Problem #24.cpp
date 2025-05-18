
#include <iostream>

using namespace std;

string UpperFirstLetter(string String)
{
	bool FirstLetter = true;

	for (size_t i = 0; i < String.length(); i++)
	{
		if (String[i] != ' ' && FirstLetter)
		{
			String[i] = toupper(String[i]);
		}

		FirstLetter = (String[i] == ' ') ? true : false;
	}

	return String;
}
int main()
{
	cout << UpperFirstLetter("abdo Waffa"); 

}

