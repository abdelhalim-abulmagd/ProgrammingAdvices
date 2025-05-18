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


void MultiplyTwoMatrixs(int ArrayLength, int MatrixArray1[100][100], int MatrixArray2[100][100], int MatrixArray3[100][100])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			MatrixArray3[Colmn][Row] = MatrixArray1[Colmn][Row] * MatrixArray2[Colmn][Row];
		}
	}
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray1[100][100];
	int MatrixArray2[100][100];
	int MatrixArray3[100][100];

	FillMatixArray(MatrixLength, MatrixArray1);
	FillMatixArray(MatrixLength, MatrixArray2);

	PrintMatrixArray(MatrixLength, MatrixArray1);
	PrintMatrixArray(MatrixLength, MatrixArray2);

	MultiplyTwoMatrixs(MatrixLength, MatrixArray1, MatrixArray2, MatrixArray3);
	PrintMatrixArray(MatrixLength, MatrixArray3);


    return 0;
}
