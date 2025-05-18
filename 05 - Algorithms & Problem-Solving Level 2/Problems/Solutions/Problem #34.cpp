#include <iostream>

using namespace std;

enum EnStatus { NotFound = -1 };

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

void FillArrayWithRandomNumbers(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(0,100);
    }
}

void PrintArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}

int SearchForNumInArray(int Num, int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        if (Array[i] == Num)
        {
            return i;
        }
    }
    return NotFound;
}

void PrintResult(int Number)
{
    if (Number == NotFound)
        cout << "NotFound\n";
    else
        cout << Number << "\n";
}

int main()
{
    srand(time(0));

    int Array[100];
    int ArrayLength = ReadArrayLength("Inter Array Length : ");
    
    FillArrayWithRandomNumbers(ArrayLength, Array);

    PrintArray(ArrayLength, Array);

    int NumberToSearch = ReadArrayLength("Inter Number To Search : ");

    NumberToSearch = SearchForNumInArray(NumberToSearch, ArrayLength, Array);

    PrintResult(NumberToSearch);

    return 0;
}
