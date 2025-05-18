#include <iostream>

using namespace std;

enum EnType { Odd, Even};

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

EnType NumberType(int Number)
{
    if (Number % 2 == 0)
        return Even;
    return Odd;
}


void CopyOddNumbers(int Array1Length, int Array1[], int &Array2Length, int Array2[])
{
    for (size_t i = 0; i < Array1Length; i++)
    {
        int ArrayElemant = Array1[i];

        if (NumberType(ArrayElemant) == Odd)
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

    CopyOddNumbers(Array1Length, Array1, Array2Length, Array2);

    PrintArray(Array2Length, Array2);

    return 0;
}
