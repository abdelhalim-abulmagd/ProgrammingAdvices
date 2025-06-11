#include <fstream>

#include "clsClint.h"
#include "clsString.h"


//------------------------------
// Global Variable
//------------------------------
static string DataFilePath = "../Data/Clients.txt";

//------------------------------
// Static Public Methods
//------------------------------

clsClint::EnStatus clsClint::GetFileStatus()
{
	fstream File;
	File.open(DataFilePath, ios::in);

	if (File.is_open())
	{
		File.close();
		return FileExist;
	}

	return FileNotFound;
}

clsClint::EnStatus clsClint::ReadFromFile(vector<clsClint>& vClints)
{
	fstream File;
	File.open(DataFilePath, ios::in);

	if (!File.is_open())
		return FileNotFound;

	string Line;
	while (getline(File, Line))
		vClints.push_back(RecordToClintObject(Line));

	return FileExist;
}

//------------------------------
// Static Private Methods
//------------------------------

clsClint clsClint::FindClint(const string& AcountNumber)
{
	vector<clsClint> vClints;
	ReadFromFile(vClints);

	for (clsClint Clint : vClints)
	{
		if (Clint.AcountNumber == AcountNumber)
		{
			Clint.SetClintStatus(ClintExist);
			return Clint;
		}
	}

	return GetEmptyClint(AcountNumber);
}

clsClint clsClint::RecordToClintObject(string Record, string Separator)
{
	clsClint Clint = GetEmptyClint("");

	vector<string> SparatedString = clsString::Split(Record, Separator);

	Clint.SetFirstName(SparatedString[0]);
	Clint.SetLastName(SparatedString[1]);
	Clint.SetEmail(SparatedString[2]);
	Clint.SetPhone(SparatedString[3]);

	Clint.AcountNumber = SparatedString[4];
	Clint.PinCode = SparatedString[5];

	Clint.CurrentBalance = stof(SparatedString[6]);
	Clint.OldBalance = stof(SparatedString[7]);

	Clint.SetClintStatus(ClintExist);

	return Clint;
}

clsClint clsClint::GetEmptyClint(const string& AccountNumber)
{
	clsClint EmptyClint = clsClint("", "", "", "", AccountNumber, "", 0, ClintNotFound);
	return EmptyClint;
}


//------------------------------
// Public Methods
//------------------------------

clsClint::clsClint(const string& AcountNumber) : clsPerson("", "", "", "")
{
	*this =  FindClint(AcountNumber);
}

clsClint::clsClint(const string& FirstName, const string& LastName, const string& Phone, const string& Email,
	const string& AcountNumber, const string& PinCode, const float& CurrentBalance, EnStatus ClintStatus)

	: clsPerson(FirstName, LastName, Phone, Email),
	AcountNumber(AcountNumber), PinCode(PinCode), CurrentBalance(CurrentBalance), ClintStatus(ClintStatus),
	OldBalance(0)
{ }

clsClint::~clsClint() { }

string clsClint::GetAcountNumber()							{ return AcountNumber; }

string clsClint::GetPinCode()								{ return PinCode; }
void clsClint::SetPinCode(const string& PinCode)			{ this->PinCode = PinCode; }

float clsClint::GetCurrentBalance()							{ return CurrentBalance; }
void clsClint::SetCurrentBalance(const float& Balance)
{ 
	OldBalance = this->CurrentBalance;
	this->CurrentBalance = Balance;
}

float clsClint::GetOldBalance()								{ return OldBalance; }

clsClint::EnStatus clsClint::GetClintStatus()				{ return ClintStatus; }

void clsClint::SetDataFilePath(const string& FilePath)		{ DataFilePath = FilePath; }

clsClint::EnStatus clsClint::Update()
{
	vector<clsClint> vClints;

	if (ReadFromFile(vClints) == FileNotFound)
		return FileNotFound;

	if (UpdateClintsVector(vClints) == Success)
		return WriteToFile(vClints);

	return ClintNotFound;
}

clsClint::EnStatus clsClint::Delete()
{
	vector<clsClint> vClints;
	if (ReadFromFile(vClints) == FileNotFound)
		return FileNotFound;

	vector<clsClint>::iterator ClintIterator;

	for (ClintIterator = vClints.begin() ; ClintIterator < vClints.end(); ClintIterator++)
	{
		if (ClintIterator->AcountNumber == AcountNumber)
		{
			vClints.erase(ClintIterator);
			return WriteToFile(vClints);
		}
	}

	return ClintNotFound;
}

clsClint::EnStatus clsClint::AddToFile()
{
	fstream File;
	File.open(DataFilePath, ios::app | ios::out);

	if (!File.is_open())
		return FailedWriteToFile;

	File << ClintDataToRecord(*this) + '\n';

	File.close();

	return Success;
}

clsClint::EnStatus clsClint::Deposit(float DepositAmount)
{
	float NewBalance = CurrentBalance + DepositAmount;

	SetCurrentBalance(NewBalance);

	clsClint::EnStatus Status = Update();
	return Status;
}

clsClint::EnStatus clsClint::Withdraw(float WithdrawAmount)
{
	if (WithdrawAmount > CurrentBalance)
		return InvalidAmount;
	
	return Deposit(-WithdrawAmount);
}

//------------------------------
// Private Methods
//------------------------------

void clsClint::SetClintStatus(EnStatus ClintStatus) { this->ClintStatus = ClintStatus; }

clsClint::EnStatus clsClint::WriteToFile(vector<clsClint> vClints)
{
	fstream File;

	File.open(DataFilePath, ios::out);

	if (!File.is_open())
		return FailedWriteToFile; 

	for (clsClint Clint : vClints)
		File << ClintDataToRecord(Clint) + '\n';

	File.close();

	return Success;
}

string clsClint::ClintDataToRecord(clsClint Clint, string Separator)
{
	string Record;

	Record += Clint.GetFirstName() + Separator;
	Record += Clint.GetLastName() + Separator;
	Record += Clint.GetEmail() + Separator;
	Record += Clint.GetPhone() + Separator;

	Record += Clint.AcountNumber + Separator;
	Record += Clint.PinCode + Separator;
	
	Record += to_string(Clint.CurrentBalance) + Separator;
	Record += to_string(Clint.OldBalance);

	return Record;
}

clsClint::EnStatus clsClint::UpdateClintsVector(vector<clsClint> &vClints)
{
	for (clsClint& Clint : vClints)
	{
		if (Clint.AcountNumber == AcountNumber)
		{
			Clint = *this;
			return Success;
		}
	}

	return ClintNotFound;
}


