#include <iostream>
#include <cmath>

using namespace std;

enum EnStatus { NotEqual, Equal};

void PrintArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}

void Swap(int &VarA, int &VarB)
{
    int Tmp = VarA;
    VarA = VarB;
    VarB = Tmp;
}

void CopyArray(int ArrayLength, int Array1[], int Array2[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Array2[i] = Array1[i];
    }
}

void ReverceArray(int ArrayLength, int Array[])
{

    for (size_t i = 0; i < (ArrayLength / 2); i++)
    {
        Swap(Array[i], Array[ArrayLength - 1 - i]);
    }
}

EnStatus IsEqual(int ArrayLength, int Array1[], int Array2[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        if (Array1[i] != Array2[i])
            return NotEqual;
    }

    return Equal;
}

int main()
{

    int ArrayLength{ 6 };
    int Array1[6]{ 10, 20,30,30,20,10 };
    int Array2[6];

    PrintArray(ArrayLength, Array1);

    CopyArray(ArrayLength, Array1, Array2);


    ReverceArray(ArrayLength, Array2);

    if (IsEqual(ArrayLength, Array1, Array2) == Equal)
        cout << "Palindrom";
    else
        cout << "Not Palindrom";

    return 0;
}
