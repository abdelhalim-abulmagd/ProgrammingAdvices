#include <iostream>

using namespace std;

int Abs(int Number)
{
    return Number <= 0 ? Number * -1 : Number;
}

int main()
{


    cout << Abs(-2) << endl;
    cout << Abs(2) << endl;
    return 0;
}
