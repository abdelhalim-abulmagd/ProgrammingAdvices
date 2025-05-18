#include <iostream>

using namespace std;

enum EnStatus
{
	NotScaler,
	Scaler
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


EnStatus CheckMatrix(int ArrayLength, int MatrixArray[3][3])
{
	
	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if ((Colmn == Row && MatrixArray[Colmn][Row] != MatrixArray[0][0]) || (Colmn != Row && MatrixArray[Colmn][Row]  != 0))
				return NotScaler;
		}
	}
	return Scaler;
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
	if (CheckMatrix(MatrixLength, MatrixArray1) == Scaler)
		cout << "Scaler";
	else
		cout << "NotScaler";

    return 0;
}
