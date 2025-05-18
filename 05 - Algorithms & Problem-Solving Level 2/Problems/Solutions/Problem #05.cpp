
#include <iostream>
#include <string>

using namespace std;

int ReadNumber(const string& Msg)
{
	int Number;
	cout << Msg;
	cin >> Number;
	return Number;
}

short GetLastNumber(int Number)
{
	return Number % 10;
}
int RemoveLastNumber(int Number)
{
	return Number / 10;
}

int ReverceNumber(int Number)
{
	string RevercedNumber = "";

	while(Number)
	{
		RevercedNumber += to_string (GetLastNumber(Number));
		Number = RemoveLastNumber(Number);
	}

	return stoi(RevercedNumber);
}

void Print(const string& Text)
{
	cout << Text << endl;
}
int main()
{
	int Number = ReadNumber("Enter Number : ");
	int RevercedNumber =  ReverceNumber(Number);

	Print(to_string(RevercedNumber));
}
