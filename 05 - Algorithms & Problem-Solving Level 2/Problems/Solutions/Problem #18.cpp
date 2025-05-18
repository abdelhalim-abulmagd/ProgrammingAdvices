
#include <iostream>
#include <string>

using namespace std;

string ReadText(const string& Msg)
{
	string Text;
	cout << Msg;
	cin >> Text;
	return Text;
}


string EncryptText(string Text, short Key = 2 )
{
	for (size_t i = 0; i < Text.length(); i++)
	{
		Text[i] = Text[i] + Key;
	}
	return Text;
}

string DecriptText(string Text, short Key = 2)
{
	for (size_t i = 0; i < Text.length(); i++)
	{
		Text[i] = Text[i] - Key;
	}
	return Text;
}

int main()
{
	string Encrypt = EncryptText(ReadText("Enter Text : "));
	cout << Encrypt;
	cout << DecriptText(Encrypt);
}