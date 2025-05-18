#include <iostream>
#include <string>

using namespace std;

enum EnASKII { A = 65, Z = 90};
enum EnType { CapitalCharacters };


int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

int ReadArrayLength(string Msg)
{
    int ArrayLength;
    cout << Msg;
    cin >> ArrayLength;

    return ArrayLength;
}

char RandomLetter(EnType Type)
{
    switch (Type)
    {
    case CapitalCharacters:
        return RandomNumber(A, Z);
    }
}


string RandomWord(EnType Type, int WordLength)
{
    string Word{ "" };

    for (size_t i = 0; i < WordLength; i++)
    {
        Word += RandomLetter(Type);
    }

    return Word;
}

string RandomKey(int KeyLength, EnType Type, int WordLength)
{
    string Key{ "" };

    for (size_t i = 0; i < KeyLength; i++)
    {
        Key += RandomWord(Type, WordLength) + "-";
    }
    return Key.substr(0, Key.length() - 1);
}

void FillArrayWithKeys(int ArrayLength, string Array[], int KeyLength, EnType Type, int WordLength)
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomKey(KeyLength, Type, WordLength);
    }
}


void PrintArray(int ArrayLength, string Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << endl;
    }
}


int main()
{
    srand(time(0));

    string Array[100];
    int ArrayLength = ReadArrayLength("Inter Array Length : ");

    FillArrayWithKeys(ArrayLength, Array, 4, CapitalCharacters, 4);
    PrintArray(ArrayLength, Array);


    return 0;
}
