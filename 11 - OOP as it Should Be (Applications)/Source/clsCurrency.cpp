#include "clsString.h"

#include "clsCurrency.h"

#include <fstream>


static string DataFilePath = "../Data/Currencies.txt";

//----------------------------------
// Public Methods
//----------------------------------

clsCurrency::clsCurrency(string CodeOrCountry)
{
	*this = Find(CodeOrCountry);
}

clsCurrency::clsCurrency(const string& Country, const string& Code, const string& CurrencyName, const float& Rate, EnStatus CurrencyStatus)
	: Country(Country), Code(Code), CurrencyName(CurrencyName), Rate(Rate), CurrencyStatus(CurrencyStatus)
{
}

clsCurrency::~clsCurrency(){}


string clsCurrency::GetCountry() { return Country; }

string clsCurrency::GetCode() { return Code; }

string clsCurrency::GetCurrencyName() { return CurrencyName; }

float clsCurrency::GetRate() { return Rate; }

void clsCurrency::SetRate(float Rate) { this->Rate = Rate; }

clsCurrency::EnStatus clsCurrency::GetCurrencyStatus() { return CurrencyStatus; }

clsCurrency::EnStatus clsCurrency::UpdateRate(float NewRate)
{
	SetRate(NewRate);

	vector<clsCurrency> vCurrencies;

	if (ReadFromFile(vCurrencies) == DataFileNotFound)
		return DataFileNotFound;

	if (UpdateCurrenciesVector(vCurrencies) == CurrencyNotExist)
		return CurrencyNotExist;

	if (WriteToFile(vCurrencies) == FaildWriteFile)
		return FaildWriteFile;

	return Success;
}

float clsCurrency::convertTo(clsCurrency TargetCurrency, float Amount)
{
	return (Amount / Rate) * TargetCurrency.Rate;
}

//----------------------------------
// Public STATIC Methods
//----------------------------------

clsCurrency::EnStatus clsCurrency::GetDataFileStatus()
{
	fstream File;

	File.open(DataFilePath, ios::in);

	if (!File.is_open())
		return DataFileNotFound;

	File.close();
	return DataFileFound;
}

string clsCurrency::StatusToString(EnStatus Status)
{

	switch (Status)
	{
	case clsCurrency::Success:
		return "Success";
	case clsCurrency::DataFileNotFound:
		return "Data File Not Found";
	case clsCurrency::DataFileFound:
		return "Data File Found";
	case clsCurrency::CurrencyNotExist:
		return "Currency Not Exist";
	case clsCurrency::CurrencyExist:
		return "Currency Exist";
	}
}

clsCurrency::EnStatus clsCurrency::ReadFromFile(vector<clsCurrency>& vCurrencies)
{
	fstream File;

	File.open(DataFilePath, ios::in);

	if (!File.is_open())
		return DataFileNotFound;

	string Line;
	while (getline(File, Line))
		vCurrencies.push_back(RecordToObj(Line));

	File.close();

	return DataFileFound;
}

//----------------------------------
// Private Methods
//----------------------------------

clsCurrency clsCurrency::Find(string CodeOrCountry)
{

	CodeOrCountry = clsString::ToLower(CodeOrCountry);

	vector<clsCurrency> vCurrencies;
	
	if (ReadFromFile(vCurrencies) == DataFileNotFound)
		return GetEmptyCurrncyObj();

	for (clsCurrency& Currncy : vCurrencies)
	{
		if (clsString::ToLower(Currncy.Code) == CodeOrCountry ||
			clsString::ToLower(Currncy.Country) == CodeOrCountry)
			return Currncy;
	}

	return GetEmptyCurrncyObj();
}



clsCurrency clsCurrency::GetEmptyCurrncyObj()
{
	return clsCurrency("", "", "", 0, CurrencyNotExist);
}

clsCurrency::EnStatus clsCurrency::UpdateCurrenciesVector(vector<clsCurrency>& vCurrencies)
{
	for (clsCurrency& Currncy : vCurrencies)
	{
		if (Currncy.Code == Code)
		{
			Currncy = *this;
			return Success;
		}
	}
	return CurrencyNotExist;
}

clsCurrency::EnStatus clsCurrency::WriteToFile(vector<clsCurrency>& vCurrencies)
{
	fstream File;

	File.open(DataFilePath, ios::out);

	if (!File.is_open())
		return FaildWriteFile;

	for (clsCurrency& Currncy : vCurrencies)
		File <<  ObjToRecord(Currncy) << '\n';

	return Success;
}

string clsCurrency::ObjToRecord(clsCurrency Currency, string Separator)
{
	string Record;

	Record = Currency.Country + Separator;
	Record += Currency.Code + Separator;
	Record += Currency.CurrencyName + Separator;
	Record += to_string(Currency.Rate) ;

	return Record;
}

//----------------------------------
// Private STATIC Methods
//----------------------------------

clsCurrency clsCurrency::RecordToObj(string Line, string Separator)
{

	vector<string> vSeperatedString = clsString::Split(Line, Separator);
	return clsCurrency(vSeperatedString[0], vSeperatedString[1], vSeperatedString[2], stof(vSeperatedString[3]), CurrencyExist);
}