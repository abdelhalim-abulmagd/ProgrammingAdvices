#include <iostream>

using namespace std;

int Ceil(float Number)
{
    
    return Number > 0 ? ++Number : Number;
    
}

int main()
{
    cout << Ceil(10.7) << endl;
    cout << Ceil(-10.7) << endl;
    return 0;
}
