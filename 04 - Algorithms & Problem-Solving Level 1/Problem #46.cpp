
#include <iostream>
#include <string>
#include <vector>

using namespace std;

enum EnASCILetters { A= 65, Z = 90, a = 97, z = 122};

vector <char> GetLetters(EnASCILetters FromLetter, EnASCILetters ToLetter)
{	
	vector <char> Letters;

	for (size_t i = FromLetter ; i <= ToLetter; i++)
	{
		Letters.push_back(char(i));
	}
	
	return Letters;
}

void Print(vector <char> Letters)
{
	for( const char& Letter : Letters)
	{
		cout << Letter << " ";
	}
}

int main()
{
	Print(GetLetters(a, z));
}
