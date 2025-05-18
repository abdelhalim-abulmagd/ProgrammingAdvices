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
	cout << endl;
}

int MinNumber(int ArrayLength, int MatrixArray[3][3])
{
	int Min = MatrixArray[0][0];
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if (MatrixArray[Colmn][Row] < Min)
				Min = MatrixArray[Colmn][Row];
		}
	}
	return Min;
}

int MaxNumber(int ArrayLength, int MatrixArray[3][3])
{
	int Max = MatrixArray[0][0];
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if (MatrixArray[Colmn][Row] > Max)
				Max = MatrixArray[Colmn][Row];
		}
	}
	return Max;
}
int main()
{
	int MatrixLength = 3;
	int MatrixArray1[3][3];

	FillMatixArray(MatrixLength, MatrixArray1);

	PrintMatrixArray(MatrixLength, MatrixArray1);
	
	cout << MinNumber(MatrixLength, MatrixArray1) << endl;
	cout << MaxNumber(MatrixLength, MatrixArray1) << endl;
    return 0;
}
