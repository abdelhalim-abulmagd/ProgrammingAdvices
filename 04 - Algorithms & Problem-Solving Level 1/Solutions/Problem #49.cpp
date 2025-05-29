
#include <iostream>
#include <string>

using namespace std;

enum EnStatus { WrongPIN, ValidPIN };

struct StAcountInfo
{
	short PIN = 1234;
	float Balance = 7500;
};


short ReadPIN(const string& Msg )
{	
	short PIN;
	cout << Msg;
	cin >> PIN;
	return PIN;
}

EnStatus IsPINValid(short PIN, short ExistPIN)
{
	if(PIN == ExistPIN)
		return ValidPIN;
	return WrongPIN;
}

string GetBalance(EnStatus Status, float Balance )
{
	StAcountInfo AcountInfo;

	switch (Status)
	{
	case WrongPIN:
		return "Wrong PIN";
	case ValidPIN :
		return to_string(Balance);
	}
}

void Print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	StAcountInfo AcountInfo;

	short PIN = ReadPIN("Enter Your PIN : ");
	EnStatus Status = IsPINValid(PIN, AcountInfo.PIN);

	Print(GetBalance(Status, AcountInfo.Balance));

}
