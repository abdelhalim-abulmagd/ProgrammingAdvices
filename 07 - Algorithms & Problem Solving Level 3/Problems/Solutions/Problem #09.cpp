#include <iostream>

using namespace std;



int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}


void FillMatixArray(int ArrayLength, int MatrixArray[100][100])
{

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			MatrixArray[Colmn][Row] = RandomNumber(1,100);
		}
	}
}


void PrintMatrixArray(int ArrayLength, int MatrixArray[100][100])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			cout << MatrixArray[Colmn][Row] << " ";
		}
		cout << endl;
	}
}

void PrintMiddleRow(int ArrayLength, int MatrixArray[100][100])
{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			cout << MatrixArray[ArrayLength/2][Row] << " ";
		}
		cout << endl;
}

void PrintMiddleColmn(int ArrayLength, int MatrixArray[100][100])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		cout << MatrixArray[Colmn][ArrayLength / 2] << " ";
	}
	cout << endl;
}


int main()
{
	int MatrixLength = 3;
	int MatrixArray1[100][100];

	FillMatixArray(MatrixLength, MatrixArray1);
	PrintMatrixArray(MatrixLength, MatrixArray1);

	PrintMiddleRow(MatrixLength, MatrixArray1);
	PrintMiddleColmn(MatrixLength, MatrixArray1);


    return 0;
}
