
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

void FillArray(int Array[], int Length)
{
    for (size_t i = 0; i < Length; i++)
    {
        Array[i] = ReadNumber("Enter Number : ");
    }
}


int CountNumberInArray(short NumberToCheck, int Array[], int Length)
{
    int Counter = 0;
    for (size_t i = 0; i < Length; i++)
    {
        if (Array[i] == NumberToCheck)
            Counter++;
    }
    return Counter;
}

void PrintArray(int Array[], int Length)
{
    for (size_t i = 0; i < Length; i++)
    {
        cout << Array[i];
    }
    cout << endl;
}

int main()
{
    int Array[100];
    
    int ArrayLength = ReadNumber("Array Size : ");
    
    FillArray(Array, ArrayLength);


    short NumberToCheck = ReadNumber("Number To Check: ");

    PrintArray(Array, ArrayLength);
    cout << CountNumberInArray(NumberToCheck, Array, ArrayLength);

}
