
#include <iostream>
#include <string>
using namespace std;

struct StData
{
	string AcountNumber;
	string PinCode;
	string Name;
	string Phone;
	float AcountBalance;

};


string DataToRecord(StData Data, string Separator = "#//#")
{
	string Record;

	Record += Data.AcountNumber + Separator;
	Record += Data.PinCode + Separator;
	Record += Data.Name + Separator;
	Record += Data.Phone + Separator;
	Record += to_string(Data.AcountBalance);

	return Record;
}



int main()
{

	StData Data;

	Data.AcountNumber = "A150";
	Data.PinCode = "1234";
	Data.Name = "Abdo";
	Data.Phone = "01008640565";
	Data.AcountBalance = 5000;


	cout << DataToRecord(Data);
}


