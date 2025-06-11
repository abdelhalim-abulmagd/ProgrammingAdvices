#pragma once 


#include <string>

using namespace std;

class clsCurrency
{
public:
	enum EnStatus { Success = 0, DataFileNotFound, DataFileFound, CurrencyNotExist, CurrencyExist, FaildWriteFile};

	clsCurrency(string CodeOrCountry);

	clsCurrency(const string& Country, const string& Code, const string& CurrencyName, const float& Rate, EnStatus CurrencyStatus);

	virtual ~clsCurrency();

	string GetCountry();
	string GetCode();
	string GetCurrencyName();
	
	float GetRate();
	void SetRate(float Rate);

	EnStatus GetCurrencyStatus();

	EnStatus UpdateRate(float NewRate);

	float convertTo(clsCurrency TargetCurrency, float Amount);

	static EnStatus GetDataFileStatus();

	static string StatusToString(EnStatus Status);

	static EnStatus ReadFromFile(vector<clsCurrency>& vCurrencies);
	
private:

	string Country;
	string Code;
	string CurrencyName;
	float Rate;

	EnStatus CurrencyStatus;

	clsCurrency Find(string CodeOrCountry);

	clsCurrency GetEmptyCurrncyObj();

	EnStatus UpdateCurrenciesVector(vector<clsCurrency>& vCurrencies);

	EnStatus WriteToFile(vector<clsCurrency>& vCurrencies);

	string ObjToRecord(clsCurrency Currency, string Separator = "#//#");

	static clsCurrency RecordToObj(string Line, string Separator = "#//#");


};