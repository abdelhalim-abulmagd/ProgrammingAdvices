
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

struct StRange
{
	int From = 1;
	int To = 10;
};

struct StTableInfo
{
	StRange MultiplicandRange;
	StRange MultiplierRange;
};

struct StUiInfo
{
	int LineWidth = 52;

};

StTableInfo TableInfo;
StUiInfo UiInfo;

void PrintTitle(int MultiplicandFrom, int MultiplicandTo, int MultipierFrom, int MultipierTo)
{
	cout << "	Multiplicand Table From " << MultiplicandFrom << " To " << MultiplicandTo << endl;
	cout << "	On Muliplier From       " << MultipierFrom << " To " << MultipierTo << endl;
}

void PrintTopRow(int From, int To)
{
	cout << "   ";

	for (size_t Number = From; Number <= To; Number++)
	{
		cout << setw(5) << Number;
	}
	cout << endl;
}

void PrintHorizontalLine(int LineWidth)
{
	for (size_t i = 0; i < LineWidth; i++)
	{
		cout << "-";
	}
	cout << endl;
}


vector <vector<short>> GetMultiplicationTable(int MultiplicandFrom, int MultiplicandTo, int MultipierFrom, int MultipierTo)
{

	vector <vector<short>> MultiplicationTable;

	for (size_t Multiplicand = MultiplicandFrom; Multiplicand <= MultiplicandTo; Multiplicand++)
	{
		vector <short> Row;

		for (size_t Multiplier = MultipierFrom; Multiplier <= MultipierTo; Multiplier++)
		{
			Row.push_back(Multiplicand * Multiplier);
		}

		MultiplicationTable.push_back(Row);
	}

	return MultiplicationTable;
}


void Print2DVector(vector<vector<short>> MultiplicationTable)
{

	for (size_t Colmn = 0; Colmn < MultiplicationTable.size(); Colmn++)
	{
		cout << setw(2) << (Colmn + 1) << "|";

		for (size_t Row = 0; Row < MultiplicationTable[Colmn].size(); Row++)
		{
			cout << setw(5) << MultiplicationTable[Colmn][Row] ;
		}
		cout << endl;
	}
}

void PrintHeader()
{
	PrintTitle(TableInfo.MultiplicandRange.From, TableInfo.MultiplicandRange.To,
		TableInfo.MultiplierRange.From, TableInfo.MultiplierRange.To);

	PrintTopRow(TableInfo.MultiplierRange.From, TableInfo.MultiplierRange.To);
	PrintHorizontalLine(UiInfo.LineWidth);
}

void PrintMultiplicationTable()
{
	vector <vector<short>> MultiplicationTable = GetMultiplicationTable(TableInfo.MultiplicandRange.From, TableInfo.MultiplicandRange.To,
		TableInfo.MultiplierRange.From, TableInfo.MultiplierRange.To);

	Print2DVector(MultiplicationTable);
}
void PrintUI()
{
	PrintHeader();
	PrintMultiplicationTable();
}

int main()
{

	PrintUI();

}
