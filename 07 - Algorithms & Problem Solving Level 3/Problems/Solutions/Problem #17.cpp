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

int IsNumberInMatrix(int Number, int ArrayLength, int MatrixArray[3][3])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if (Number == MatrixArray[Colmn][Row])
				return true;
		}
	}
	return false;
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

	cout << IsNumberInMatrix(3, MatrixLength, MatrixArray1) << endl;


    return 0;
}
