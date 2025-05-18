
#include <iostream>

using namespace std;



int CountUpperLetters(string String)
{
	int Counter = 0;

	for (size_t i = 0; i < String.length(); i++)
	{
		if (isupper(String[i]))
			Counter++;
	}
	return Counter;
}

int CountLowerLetters(string String)
{
	int Counter = 0;

	for (size_t i = 0; i < String.length(); i++)
	{
		if (islower(String[i]))
			Counter++;
	}
	return Counter;
}


int main()
{

	string String = ("aa  AAAA  aaa");

	cout << String.length() << endl;
	cout << CountUpperLetters(String) << endl;
	cout << CountLowerLetters(String) << endl;

}


