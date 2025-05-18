
#include <iostream>
#include <string>

using namespace std;

int GetRandomNumber(int From, int To)
{
	srand(time(0));
	return rand() % (To - From + 1 ) + From ;
}

int main()
{

	cout << GetRandomNumber(5, 10 );
}