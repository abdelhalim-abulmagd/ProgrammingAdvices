#include <iostream>

using namespace std;

int RandomNumber(int From, int To)
{
	return rand() % (To - From + 1) + From;
}


void FillMatixArray(int ArrayLength, int MatrixArray[3][3])
{

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			MatrixArray[Colmn][Row] = RandomNumber(1, 10);
		}
	}
}


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
}

int CountNumberInMatrix(int Number, int ArrayLength, int MatrixArray[3][3])
{
	int Counter = 0;
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if (Number == MatrixArray[Colmn][Row])
				Counter++;
		}
	}
	return Counter;
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray1[3][3];

	FillMatixArray(MatrixLength, MatrixArray1);
	PrintMatrixArray(MatrixLength, MatrixArray1);

	cout << CountNumberInMatrix(1, MatrixLength, MatrixArray1) << endl;
	cout << CountNumberInMatrix(5, MatrixLength, MatrixArray1) << endl;
	cout << CountNumberInMatrix(4, MatrixLength, MatrixArray1) << endl;


    return 0;
}
