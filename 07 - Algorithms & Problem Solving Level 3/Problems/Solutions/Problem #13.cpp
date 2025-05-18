#include <iostream>

using namespace std;

enum EnStatus
{
	NotIdentity,
	Identity
};

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
/*
--------------// My Solution
* 
EnStatus CheckMatrix(int ArrayLength, int MatrixArray[3][3])
{
	if (MatrixArray[0][0] == 1 && MatrixArray[ArrayLength / 2][ArrayLength / 2] == 1 && MatrixArray[ArrayLength - 1][ArrayLength - 1] == 1)
	{
		for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
		{
			for (size_t Row = 0; Row < ArrayLength; Row++)
			{
				if ((MatrixArray[Colmn][Row] > 1) )
					return NotIdentity;

			}
		}
		return Identity;
	}

	return NotIdentity;
}
*/

EnStatus CheckMatrix(int ArrayLength, int MatrixArray[3][3])
{
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if ((Colmn == Row && MatrixArray[Colmn][Row] != 1) || (Colmn != Row && MatrixArray[Colmn][Row]  != 0))
				return NotIdentity;
		}
	}
	return Identity;
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray1[3][3]{
		{1,0,0},
		{0,1,0},
		{0,0,1}
	};


	PrintMatrixArray(MatrixLength, MatrixArray1);
	if (CheckMatrix(MatrixLength, MatrixArray1) == Identity)
		cout << "Identity";
	else
		cout << "NotIdentity";

    return 0;
}
