
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum EnType { CapitalLetter };
enum EnASCII { A = 65, Z = 90 };

struct StKeyInfo
{
    int CountKey;
    int KeyLength;
    int WordLength;
};

int ReadNumber(const string& Msg)
{
    int Number;
    cout << Msg;
    cin >> Number;
    return Number;
}

StKeyInfo ReadKeyInfo()
{
    StKeyInfo KeyInfo;

    KeyInfo.CountKey = ReadNumber("Count Keys : ");
    KeyInfo.KeyLength = ReadNumber("Key Length : ");
    KeyInfo.WordLength = ReadNumber("Word Length : ");

    return KeyInfo;
}

int GetRandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

char GetRandom(EnType Type)
{
    switch (Type)
    {
    case CapitalLetter:
        return GetRandomNumber(A, Z);
    }
}

string GetRandomWord(int WordLength)
{
    string Word = "";

    for (size_t i = 0; i < WordLength; i++)
    {
        Word += GetRandom(CapitalLetter);
    }
    return Word;
}

string GetKey(int KeyLength, int WordLength)
{
    string Key = "";

    for (size_t i = 0; i < KeyLength; i++)
    {

        Key += GetRandomWord(WordLength) + '-';
    }

    // substr Will Remove Last '-' in String : Becose For Loop Add One Extra '-' 
    return Key.substr(0, Key.length() - 1);
}

vector <string> GetKeys(int CountKeys, int KeyLength, int WordLength)
{
    vector <string> Keys;

    for (size_t i = 0; i < CountKeys; i++)
    {
        Keys.push_back(GetKey(KeyLength, WordLength));
    }

    return Keys;
}

void PrintKeys(vector <string> Keys)
{
    for (string Key : Keys)
        cout << Key << '\n';
}
    
int main()
{
    srand(time(0));

    StKeyInfo KeyInfo = ReadKeyInfo();

    PrintKeys(GetKeys(KeyInfo.CountKey, KeyInfo.KeyLength, KeyInfo.WordLength));

}
