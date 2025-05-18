
#include <iostream>

using namespace std;

enum EnTrim { eLeft, eRight, eAll };
/*
* Mohamed Abu Hadhud 
 

string TrimLeft(string S1)
{
	for (short i = 0; i < S1.length(); i++)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(i, S1.length() - i);
		}
	}
}


string TrimRight(string S1)
{
	for (short i = S1.length() - 1; i >= 0; i--)
	{
		if (S1[i] != ' ')
		{
			return S1.substr(0, i + 1);
		}
	}

}


*/
string TrimLeft(string String, char Character = ' ')
{
	for (size_t i = 0; i < String.length(); i++)
	{
		if (String[i] == Character)
		{
			String.erase(0, i + 1);
			i--;
		}
		else
			return String;
	}
}

string TrimRight(string String, char Character = ' ')
{
	for (size_t i = String.length() - 1; i > 0 ; i--)
	{
		if (String[i] == Character)
		{
			String.erase(i, String.length());
		}
		else
			return String;
	}
}

string Trim(string String, EnTrim TrimMode = EnTrim::eAll)
{
	switch (TrimMode)
	{
	case eLeft:
		return TrimLeft(String);
	case eRight:
		return TrimRight(String);
	case eAll:
		return TrimLeft(TrimRight(String));
	}
}
int main()
{
	string String = "            Abdo Waffa      ";



	cout << Trim(String, eLeft) << endl;
	cout << Trim(String, eRight) << "--" << endl;
	cout << Trim(String, eAll) << "--" << endl;
}


