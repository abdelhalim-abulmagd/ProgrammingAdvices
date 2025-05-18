
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



int main()
{
    int Array[100];
    
    int ArrayLength = ReadNumber("Array Length : ");
    
    FillArray(Array, ArrayLength);

    PrintArray(Array, ArrayLength);

}
