
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
	for (size_t Colmn = 1; Colmn <= Number ; Colmn++)
	{
		for (size_t Row = 1; Row <=  Colmn; Row++)
		{
			cout << Colmn;
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedNumber(5);
}