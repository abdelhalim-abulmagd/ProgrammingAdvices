#include <iostream>
#include <cmath>

using namespace std;

enum EnType { NotPrime, Prime, Odd, Even};

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
        Array[i] = RandomNumber(0, 100);
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


EnType NumberType(int Dividend, int Divisor = 0)
{
    if (Dividend % Divisor == 0)
        return Even;
    return Odd;
}



EnType IsPrime(int Number)
{
    int Sqrt = sqrt(Number);

    for (size_t i = 1; i < Sqrt; i++)
    {
        if (NumberType(Number, i) == Even)
            return NotPrime;
    }
    return Prime;
}


void CopyPrimeNumbers(int Array1Length, int Array1[], int &Array2Length, int Array2[])
{
    for (size_t i = 0; i < Array1Length; i++)
    {
        int ArrayElemant = Array1[i];

        if (IsPrime(ArrayElemant) == Prime)
            Array2[Array2Length++] = Array1[i];
    }
}

int main()
{
    srand(time(0));

    int Array1[100];
    int Array2[100];

    int Array1Length = ReadArrayLength("Inter Array Length : ");
    int Array2Length{0};

    FillArrayWithRandomNumbers(Array1Length, Array1);
    PrintArray(Array1Length, Array1);

    CopyPrimeNumbers(Array1Length, Array1, Array2Length, Array2);

    PrintArray(Array2Length, Array2);

    return 0;
}
