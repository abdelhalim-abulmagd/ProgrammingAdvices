#include <iostream>

using namespace std;


int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Array[i] = RandomNumber(-100, 100);
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

int CountNigativeNumberInArray(int ArrayLength, int Array[])
{
    int Counter = 0;

    for (size_t i = 0; i < ArrayLength; i++)
    {
        if (Array[i] <= 0)
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

    cout << CountNigativeNumberInArray(ArrayLength, Array);
    return 0;
}
