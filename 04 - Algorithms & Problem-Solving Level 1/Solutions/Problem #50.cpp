
#include <iostream>
#include <string>

using namespace std;

enum EnStatus { WrongPIN, ValidPIN };
enum EnInfo { TimesToTry = 3 };

struct StAcountInfo
{
	short PIN = 1234;
	float Balance = 7500;
};
StAcountInfo AcountInfo;


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


EnStatus ReadPINSeveralTimes(const string& Msg )
{
	short PIN;

	for (size_t i = 0; i < TimesToTry; i++)
	{
		PIN = ReadPIN(Msg);

		if(IsPINValid(PIN, AcountInfo.PIN) == ValidPIN)
			return ValidPIN;
	}
	return WrongPIN;
}


string GetBalance(EnStatus Status)
{
	switch (Status)
	{
	case WrongPIN:
		return "Wrong PIN";
	case ValidPIN :
		return to_string(AcountInfo.Balance);
	}
}

void Print(const string &text)
{
	cout << text << '\n';
}

int main()
{

	EnStatus Status = ReadPINSeveralTimes("Enter PIN : ");
	Print(GetBalance(Status));

}
