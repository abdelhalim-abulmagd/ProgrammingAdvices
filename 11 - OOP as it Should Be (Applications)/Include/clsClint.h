#pragma once

#include "clsPerson.h"
#include <vector>

using namespace std;

class clsClint : public clsPerson
{

public:

	enum EnStatus { FailedWriteToFile, ClintNotFound, FileNotFound, FileExist, ClintExist, InvalidAmount, Success};

	clsClint(const string& AcountNumber);

	clsClint(const string& FirstName, const string& LastName, const string& Phone, const string& Email,
		const string& AcountNumber, const string& PinCode, const float& CurrentBalance, EnStatus ClintStatus);

	virtual ~clsClint();

	string GetAcountNumber();

	string GetPinCode();
	void SetPinCode(const string& PinCode);

	float GetCurrentBalance();
	void SetCurrentBalance(const float& Balance);

	float GetOldBalance();

	EnStatus GetClintStatus();

	void SetDataFilePath(const string& FilePath);

	EnStatus Update();

	EnStatus Delete();

	EnStatus AddToFile();

	EnStatus Deposit(float DepositAmount);

	EnStatus Withdraw(float WithdrawAmount);

	static EnStatus ReadFromFile(vector<clsClint>& vClints);

	static EnStatus GetFileStatus();

private:

	EnStatus ClintStatus;

	string AcountNumber;
	string PinCode;

	float CurrentBalance;
	float OldBalance;

	void SetClintStatus(EnStatus ClintStatus);

	EnStatus WriteToFile(vector<clsClint> vClints);

	string ClintDataToRecord(clsClint Clint, string Separator = "#//#");

	clsClint::EnStatus UpdateClintsVector(vector<clsClint>& vClints);

	static clsClint FindClint(const string& AcountNumber);

	static clsClint RecordToClintObject(string String, string Separator = "#//#");

	static clsClint GetEmptyClint(const string& AcountNumber);

};