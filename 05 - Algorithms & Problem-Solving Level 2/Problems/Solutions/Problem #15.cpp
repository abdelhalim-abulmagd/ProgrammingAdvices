
#include <iostream>
#include <string>

using namespace std;

enum EnLettersASCII { A = 65, Z = 90 };

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

void PrintInvertedLetter(int N)
{
	for (size_t Colmn = A  ; Colmn <= A + N - 1 ; Colmn++)
	{
		for (size_t Row = A ; Row <= Colmn; Row++)
		{
			cout << char(Colmn);
		}
		cout << endl;
	}
}

int main()
{
	PrintInvertedLetter(5);
}