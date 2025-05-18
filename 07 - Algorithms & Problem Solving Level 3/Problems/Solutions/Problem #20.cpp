#include <iostream>

using namespace std;



void PrintMatrixArray(int ArrayLength, int MatrixArray[3][3])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			cout << MatrixArray[Colmn][Row] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

bool IsPalindrom(int ArrayLength, int MatrixArray[3][3])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength/2; Row++) //  Row / 2 Coz You Dont Need to Go to Last Element
		{
			if (MatrixArray[Colmn][Row] != MatrixArray[Colmn][ArrayLength - 1 - Row])
				return false;
		}
	}
	return true;
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray1[3][3]{
		{1,2,1},
		{1,2,1},
		{1,2,1}
	};


	PrintMatrixArray(MatrixLength, MatrixArray1);
	cout << IsPalindrom(MatrixLength, MatrixArray1);
    return 0;
}
