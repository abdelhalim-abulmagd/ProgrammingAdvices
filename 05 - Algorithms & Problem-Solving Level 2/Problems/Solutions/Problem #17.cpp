
#include <iostream>
#include <string>

using namespace std;

enum EnLettersASCII { A = 65, Z = 90 };

string ReadPassword(const string& Msg)
{
	string Password;
	cout << Msg;
	cin >> Password;
	return Password;
}

string ToUpper(string Text)
{
	string UpperText = "";
	for (size_t i = 0; i < Text.length(); i++)
	{
		UpperText += toupper(Text[i]);
	}
	return UpperText;
}

int GussPassword(string Password)
{
	int Trail = 0;

	Password = ToUpper(Password);

	for (size_t Colmn = A; Colmn <= Z; Colmn++)
	{
		for (size_t OuterRow = A; OuterRow <= Z; OuterRow++)
		{
			for (size_t InnerRow = A; InnerRow <= Z; InnerRow++)
			{
				string Word = "";
				Word = Colmn;
				Word += OuterRow;
				Word += InnerRow;

				if (Password == Word)
					return Trail;

				Trail++;
			}
		}
	}
}

int main()
{
	cout << GussPassword(ReadPassword("Enter Passoword : "));
}