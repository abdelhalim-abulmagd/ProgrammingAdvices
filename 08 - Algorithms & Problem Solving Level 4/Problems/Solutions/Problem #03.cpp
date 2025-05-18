
#include <iostream>

using namespace std;

bool IsLeepYear(short Year)
{
	return (Year % 400 == 0) || (Year % 4 == 0 && Year % 100 != 0);
}

int main()
{
	cout << IsLeepYear(1971);
}
