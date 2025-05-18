#include <iostream>
#include <vector>

using namespace std;



int RandomNumber(int From, int To)
{
    return rand() % (To - From + 1) + From;
}


void FillMatixArray(int ArrayLength, int MatrixArray[100][100])
{
	int counter = 0;

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			MatrixArray[Colmn][Row] = ++counter;
		}
	}
}

void CopyTransposedMatrix(int ArrayLength, int MatrixArray1[100][100], int MatrixArray2[100][100])
{

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			MatrixArray2[Colmn][Row] = MatrixArray1[Row][Colmn];
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



int main()
{
	int MatrixLength = 3;
	int MatrixArray1[100][100];
	int MatrixArray2[100][100];

	FillMatixArray(MatrixLength, MatrixArray1);
	PrintMatrixArray(MatrixLength, MatrixArray1);

	CopyTransposedMatrix(MatrixLength, MatrixArray1, MatrixArray2);
	PrintMatrixArray(MatrixLength, MatrixArray2);

    return 0;
}
