
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

void PrintInvertedLetter(int Number)
{
	for (size_t Colmn = A + Number - 1 ; Colmn >= A ; Colmn--)
	{
		for (size_t Row = A; Row <=  Colmn; Row++)
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