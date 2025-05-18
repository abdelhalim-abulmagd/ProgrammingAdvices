
#include <iostream>
#include <string>

using namespace std;
enum EnLettersASCII { A = 65, Z = 90 };

void PrintLetter()
{
	for (size_t Colmn = 1; Colmn <= 3; Colmn++)
	{
		for (size_t Row = A; Row <= Z; Row++)
		{
			if (Colmn == 1)
				cout << char(A) << char(A) << char(Row) << endl;
			if (Colmn == 2)
				cout << char(A) << char(Row) << char(Z) << endl;
			if (Colmn == 3)
				cout << char(Row) << char(Z) << char(Z) << endl;
		}
	}
}

int main()
{
	PrintLetter();
}