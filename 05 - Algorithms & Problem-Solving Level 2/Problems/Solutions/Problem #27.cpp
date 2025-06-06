
#include <iostream>
#include <vector>
#include <string>

using namespace std;


int ReadNumber(const string& Msg)
{
    int Number;
    cout << Msg;
    cin >> Number;
    return Number;
}

int GetRandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}

void FillArray(int Array[], int Length)
{
    for (size_t i = 0; i < Length; i++)
    {
        Array[i] = GetRandomNumber(1, 100);
    }
}


void PrintArray(int Array[], int Length)
{
    for (size_t i = 0; i < Length; i++)
    {
        cout << Array[i] << ' ';
    }
    cout << endl;
}


int GetSumNumbersInArray(int Array[], int Length)
{
    int SumNumbers = 0;

    for (size_t i = 0; i < Length; i++)
    {
        SumNumbers += Array[i];
    }

    return SumNumbers;
}

float GetAvrage(int Number, int Denamerator)
{
    return (float)Number / Denamerator;
}

int main()
{
    int Array[100];
    
    int ArrayLength = ReadNumber("Array Length : ");
    
    FillArray(Array, ArrayLength);

    PrintArray(Array, ArrayLength);
    cout << GetAvrage(GetSumNumbersInArray(Array, ArrayLength), ArrayLength);

}
