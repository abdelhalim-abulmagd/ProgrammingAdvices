
#include <iostream>

using namespace std;

string LowerFirstLetter(string String)
{
	bool FirstLetter = true;

	for (size_t i = 0; i < String.length(); i++)
	{
		if (String[i] != ' ' && FirstLetter)
		{
			String[i] = tolower(String[i]);
		}

		FirstLetter = (String[i] == ' ') ? true : false;
	}

	return String;
}
int main()
{
	cout << LowerFirstLetter("Abdo Waffa");

}

