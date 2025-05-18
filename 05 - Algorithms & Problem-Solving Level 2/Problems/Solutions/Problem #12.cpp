
#include <iostream>
#include <string>

using namespace std;

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

void PrintInvertedNumber(int Number)
{
	for (size_t Colmn = 0; Colmn < Number; Colmn++)
	{
		for (size_t Row = 0; Row < Number - Colmn; Row++)
		{
			cout << Number - Colmn;
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedNumber(9);
}