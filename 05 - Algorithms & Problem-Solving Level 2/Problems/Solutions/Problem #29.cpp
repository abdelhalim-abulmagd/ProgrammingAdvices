
#include <iostream>
#include <vector>
#include <string>

using namespace std;

enum EnType { NotPrime, Prime};


int ReadNumber(const string& Msg)
{
    int Number;
    cout << Msg;
    cin >> Number;
    return Number;
}

EnType IsPrime(int Number)
{
    int Sqrt = sqrt(Number);

    for (size_t i = 2; i < Sqrt; i++)
    {
        if (Number % i == 0)
            return NotPrime;
    }
    
    return Prime;
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

void CopyPrimeNumbersFromArray(int OriginalArray[], int SecondArray[], int OriginalArrayLength, int &SecondArrayLength)
{
    for (size_t i = 0; i < OriginalArrayLength; i++)
    {
        if (IsPrime(OriginalArray[i]) == Prime)
        {
            SecondArray[SecondArrayLength] = OriginalArray[i] ;
            SecondArrayLength++;
        }

    }
}

int main()
{
    srand(time(0));

    int Array[100];
    int Array2[100];
    
    int ArrayLength = ReadNumber("Array Length : ");
    int SecondArrayLength = 0;

    FillArray(Array, ArrayLength);

    PrintArray(Array, ArrayLength);

    CopyPrimeNumbersFromArray(Array, Array2, ArrayLength, SecondArrayLength);
    PrintArray(Array2, SecondArrayLength);


}
