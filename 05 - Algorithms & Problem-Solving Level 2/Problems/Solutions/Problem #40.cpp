#include <iostream>
#include <cmath>

using namespace std;


void PrintArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}


bool IsExist(int Number, int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        if (Number == Array[i])
            return true;
    }
    return false;
}

void GetDistinctNumber(int Array1Length, int Array1[], int &Array2Length, int Array2[])
{
    for (size_t i = 0; i < Array1Length; i++)
    {
        if (!IsExist(Array1[i], Array2Length, Array2))
            Array2[Array2Length++] = Array1[i];
    }
}

int main()
{

    int Array1Length{ 10 };
    int Array2Length{ 0 };
    int Array1[10]{ 10, 10, 10, 50, 50, 70,70,70,70,90 };
    int Array2[100];


    GetDistinctNumber(Array1Length, Array1, Array2Length, Array2);
    PrintArray(Array1Length, Array1);
    PrintArray(Array2Length, Array2);
    return 0;
}
