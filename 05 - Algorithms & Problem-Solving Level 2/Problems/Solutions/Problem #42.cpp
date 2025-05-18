#include <iostream>

using namespace std;

enum EnType {Odd, Even };

int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(1, 100);
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

int ReadNumber(string Msg)
{
    cout << Msg;
    int Number;
    cin >> Number ;
    return Number;
}

EnType GetNumberType(int Number)
{
    if (Number % 2 == 0)
        return Even;
    return Odd;
}

int CountOddNumberInArray(int ArrayLength, int Array[])
{
    int Counter = 0;

    for (size_t i = 0; i < ArrayLength; i++)
    {
        if (GetNumberType(Array[i]) == Odd)
            Counter++;
    }
    return Counter;
}

int main()
{

    int ArrayLength = ReadNumber("Inter The Length : ");
    int Array[100];

    FillArrayWithRandomNumbers(ArrayLength, Array);
    PrintArray(ArrayLength, Array);

    cout << CountOddNumberInArray(ArrayLength, Array);
    return 0;
}
