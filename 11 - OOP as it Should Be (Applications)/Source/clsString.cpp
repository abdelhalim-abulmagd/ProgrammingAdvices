#include "clsString.h"


clsString::clsString(const string& String) : String(String) {}

clsString::~clsString() {}



//----------------------------
// Public Static Methods
//----------------------------

vector<string> clsString::Split(string StringToSplit, string Separator)
{
	int Position = 0;
	string Word;
	vector<string> SparatedString;

	while ((Position = StringToSplit.find(Separator)) != string::npos)
	{
		Word = StringToSplit.substr(0, Position);

		if (Word != "")
			SparatedString.push_back(Word);
		StringToSplit.erase(0, Position + Separator.length());
	}

	if (StringToSplit != "")
		SparatedString.push_back(StringToSplit);

	return SparatedString;
}

string clsString::NumberToText(long long int Number)
{
    string Text = "";

    string OneToNine[]{ "", "One", "Two", "Three",  "Four", "Five",
        "Six",  "Seven", "Eight", "Nine","Ten",
        "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen",
        "Sixteen", "Seventeen", "Eighteen", "Nineteen" };

    string Tens[]{ "", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety" };

    long long int Tmp = Number;

    if (Number < 0)
    {
        Number = -Number;
        Text += "Negative ";
    }

    if (Number <= 19)
    {
        Text += OneToNine[Number];
        return Text;
    }

    else if (Number >= 20 && Number <= 99)
    {
        int Remainder = Number / 10;

        Text += Tens[Remainder] + " ";

        Text += NumberToText(Number % 10);
        return Text;
    }

    else if (Number >= 100 && Number <= 999)
    {

        int Remainder = Number / 100;

        Text += OneToNine[Remainder] + " Hundreds ";
        Text += NumberToText(Number % 100);
        return Text;
    }

    else if (Number >= 1000 && Number <= 9999)
    {

        int Remainder = Number / 1000;

        Text += OneToNine[Remainder] + " Thousands ";
        Text += NumberToText(Number % 1000);
        return Text;
    }
    else if (Number >= 10000 && Number <= 99999)
    {

        int Remainder = Number / 10000;

        Text += Tens[Remainder] + "-";
        Text += NumberToText(Number % 10000);
        return Text;
    }
    else if (Number >= 100000 && Number <= 999999)
    {

        int Remainder = Number / 100000;

        Text += OneToNine[Remainder] + " Hundred ";
        Text += NumberToText(Number % 100000);
        return Text;
    }

    else if (Number >= 1000000 && Number <= 9999999)
    {

        int Remainder = Number / 1000000;

        Text += OneToNine[Remainder] + " Million ";
        Text += NumberToText(Number % 1000000);
        return Text;
    }

    return Text;
}

string clsString::Replace(string WordToReplace, string ReplaceTo, string String, bool MatchCase)
{
    int Position = 0;
    int WordToReplaceLength = WordToReplace.length();

    if (!MatchCase)
    {
        String = ToLower(String);
        WordToReplace = ToLower(WordToReplace);
    }

    while ((Position = String.find(WordToReplace)) != string::npos)
    {

        String.erase(Position, WordToReplaceLength);
        String.insert(Position, ReplaceTo);
    }
    return String;
}

string clsString::ToLower(string String)
{
    for (size_t i = 0; i < String.length(); i++)
    {
        String[i] = tolower(String[i]);
    }
    return String;
}

//----------------------------
// Public Methods
//----------------------------

string clsString::GetString() { return String; }

void clsString::SetString(string String) { this->String = String; }

vector<string> clsString::Split(string Separator)
{
	vector<string> SparatedString = Split(String, Separator);
	return SparatedString;
}

void clsString::Replace(string WordToReplace, string ReplaceTo, bool MatchCase)
{
    String = Replace(WordToReplace, ReplaceTo, String, MatchCase);
}

void clsString::ToLower()
{
    String = ToLower(String);
}
