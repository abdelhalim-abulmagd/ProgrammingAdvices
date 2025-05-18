
#include <iostream>

using namespace std;

void PrintFirstLetter(string String)
{

	if (String[0] != ' ')
	{
		cout << String[0];
	}

	int position = String.find(' ');

	if (position != string::npos)
	{
		PrintFirstLetter(String.substr(++position, String.length()));
	}


}
int main()
{

	PrintFirstLetter("          Abdo       Waffa                  Bdeer            ");
}

