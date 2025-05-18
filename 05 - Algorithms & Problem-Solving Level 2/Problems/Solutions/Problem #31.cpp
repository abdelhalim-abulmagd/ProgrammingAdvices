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

void FillArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Array[i] = i+1;
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

void Swap(int &VarA, int &VarB)
{
    int Tmp = VarA;
    VarA = VarB;
    VarB = Tmp;
}

void SuffleArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        Swap(Array[i], Array[RandomNumber(0, ArrayLength-1)]);
    }
}

int main()
{
    srand(time(0));

    int Array[100];
    int ArrayLength = ReadArrayLength("Inter Array Length : ");

    FillArray(ArrayLength, Array);

    PrintArray(ArrayLength, Array);

    SuffleArray(ArrayLength, Array);
    PrintArray(ArrayLength, Array);

    return 0;
}
