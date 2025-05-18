#include <iostream>

using namespace std;

enum EnStatus { No, Yes };


int ReadNumber(string Msg)
{
    int ArrayLength;
    cout << Msg;
    cin >> ArrayLength;

    return ArrayLength;
}



void PrintArray(int ArrayLength, int Array[])
{
    for (size_t i = 0; i < ArrayLength; i++)
    {
        cout << Array[i] << " ";
    }
    cout << "\n";
}


EnStatus YesNoQS(string Msg)
{
    cout << Msg;
    char Answer;
    cin >> Answer;
    return tolower(Answer) == 'y' ? Yes : No;
}

void FillArray(int &ArrayLength, int Array[])
{
    do
    {
        Array[ArrayLength++] = ReadNumber("Inter Number : ");

    } while (YesNoQS("Do U Want Add More : ") == Yes);
}

int main()
{
    srand(time(0));

    int ArrayLength = 0;
    int Array[100];

    FillArray(ArrayLength, Array);

    cout << ArrayLength << '\n';
    PrintArray(ArrayLength, Array);

    return 0;
}
