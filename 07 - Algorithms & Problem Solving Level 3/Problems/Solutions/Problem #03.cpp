#include <iostream>
#include <vector>

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
			MatrixArray[Colmn][Row] = RandomNumber(0, 100);
		}
	}
}

vector<int> SumRows(int ArrayLength, int MatrixArray[100][100])
{
	vector<int> Result;
	int Sum = 0;

	for (size_t Colmn = 0; Colmn < ArrayLength; Colmn++)
	{
		for (size_t Row = 0; Row < ArrayLength; Row++)
		{
			Sum += MatrixArray[Colmn][Row];
		}
		Result.push_back(Sum);
	}
	return Result;
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

void Print(vector<int> Items)
{
	for (int item : Items)
		cout << "Row Sum : " << item << endl;;
}

int main()
{
	int MatrixLength = 3;
	int MatrixArray[100][100];
	
	FillMatixArray(MatrixLength, MatrixArray);
	PrintMatrixArray(MatrixLength, MatrixArray);
	Print(SumRows(MatrixLength, MatrixArray));

    return 0;
}
