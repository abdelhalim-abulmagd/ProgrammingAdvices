#include <iostream>
#include <vector>

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

vector<int> GetDuplicatedNumber(int ArrayLength, int MatrixArray1[3][3], int MatrixArray2[3][3])
{
	vector<int> DuplicatedNumber;

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			if (IsNumberInMatrix(MatrixArray1[Colmn][Row], ArrayLength, MatrixArray2))
				DuplicatedNumber.push_back(MatrixArray1[Colmn][Row]);
		}
	}
	return DuplicatedNumber;
}

void Print(vector<int> Items)
{
	for (int Item : Items)
		cout << Item << " ";
}
int main()
{
	int MatrixLength = 3;
	int MatrixArray1[3][3];
	int MatrixArray2[3][3];

	FillMatixArray(MatrixLength, MatrixArray1);
	FillMatixArray(MatrixLength, MatrixArray2);

	PrintMatrixArray(MatrixLength, MatrixArray1);
	
	PrintMatrixArray(MatrixLength, MatrixArray2);

	Print(GetDuplicatedNumber(MatrixLength, MatrixArray1, MatrixArray2));

    return 0;
}
