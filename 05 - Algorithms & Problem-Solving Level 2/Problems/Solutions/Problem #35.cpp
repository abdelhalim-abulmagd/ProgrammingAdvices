#include <iostream>

using namespace std;

enum EnStatus { NotFound = -1, Found = 1};


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

EnStatus IsExist(int Num, int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
            return Found;
    }
    return NotFound;
}

void PrintResult(EnStatus Status)
{
    if (Status == NotFound)
        cout << "NotFound\n";
    else
        cout << "Found\n";
}

int main()
{
    srand(time(0));

    int Array[100];
    int ArrayLength = ReadArrayLength("Inter Array Length : ");
    
    FillArrayWithRandomNumbers(ArrayLength, Array);

    PrintArray(ArrayLength, Array);

    int NumberToSearch = ReadArrayLength("Inter Number To Search : ");


    PrintResult(IsExist(NumberToSearch, ArrayLength, Array));

    return 0;
}
