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

bool IsSpace(int ArrayLength, int MatrixArray[3][3])
{
	return CountNumberInMatrix(0, ArrayLength, MatrixArray) > ((ArrayLength * 3) / 2) ;
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray1[3][3]{
		{0,0,0},
		{3,3,3},
		{3,3,3}
	};

	PrintMatrixArray(MatrixLength, MatrixArray1);

	cout << IsSpace(MatrixLength, MatrixArray1) << endl;


    return 0;
}
