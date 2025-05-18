#include <iostream>

using namespace std;

int Round(float Number)
{
    int WholeNumber = static_cast<int> (Number);
    float Fractions = Number - WholeNumber;
    
    return Fractions > 0.5 ? ++WholeNumber : WholeNumber;
    
}

int main()
{


    cout << Round(10.7) << endl;
    cout << Round(10.3) << endl;
    cout << Round(-11.7) << endl;
    return 0;
}
