#include <iostream>

using namespace std;

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
    cout << endl;
}

void Swap(int& VarA, int& VarB)
{
    int Tmp = VarA;
    VarA = VarB;
    VarB = Tmp;
}

void ReverceArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < (ArrayLength / 2); i++)
    {
        int LastElemant = ArrayLength - 1 - i;
        Swap(Array[i], Array[LastElemant]);
    }
}
int main()
{
    srand(time(0));

    int Array[100];
    int ArrayLength = ReadArrayLength("Inter Array Length : ");

    FillArrayWithRandomNumbers(ArrayLength, Array);

    PrintArray(ArrayLength, Array);

    ReverceArray(ArrayLength, Array);
    PrintArray(ArrayLength, Array);
    return 0;
}
