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

int SumMatrix(int ArrayLength, int MatrixArray[100][100])
{
	int ResultSum = 0;

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			ResultSum += MatrixArray[Colmn][Row];
		}
	}
	return ResultSum;
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray1[100][100];

	FillMatixArray(MatrixLength, MatrixArray1);
	PrintMatrixArray(MatrixLength, MatrixArray1);


	cout << SumMatrix(MatrixLength, MatrixArray1);

    return 0;
}
