#include <iostream>

using namespace std;

int Floar(float Number)
{
    
    return Number < 0? --Number : Number;
    
}

int main()
{
    cout << Floar(10.3) << endl;
    cout << Floar(11.3) << endl;
    cout << Floar(-10.3) << endl;
    return 0;
}
