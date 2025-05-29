#include "clsUser.h"
#include "clsString.h"
#include "clsDate.h"

#include <fstream>


//------------------------------
// Global Variable
//------------------------------
static string DataFilePath = "../Data/Users.txt";
static string LogFilePath = "../Data/Log.txt";


//------------------------------
// Public Methods
//------------------------------

clsUser::clsUser(const string& UserName) : clsPerson("", "", "", "")
{
	*this = FindUser(UserName);
}

clsUser::clsUser(const string& UserName, const string& Password) : clsPerson("", "", "", "")
{
	clsUser User = FindUser(UserName);

	if (User.Password == Password)
		*this = User;
	else
		*this = GetEmptyUser(UserName);
}

clsUser::clsUser(const string& FirstName, const string& LastName, const string& Phone, const string& Email,
	const string& UserName, const string& Password, const int& Permissions, EnStatus UserStatus)

	: clsPerson(FirstName, LastName, Phone, Email),
	UserName(UserName), Password(Password), Permissions(Permissions), UserStatus(UserStatus) {
}

clsUser::~clsUser() {}

clsUser::EnStatus clsUser::GetUserStatus() { return UserStatus; }

string clsUser::GetUserName() { return UserName; }

string clsUser::GetPassword() { return Password; }
void clsUser::SetPassword(const string& Password) { this->Password = Password; }

int clsUser::GetPermissions() { return Permissions; }
void clsUser::SetPermissions(const int& Permissions) { this->Permissions = Permissions; }

clsUser::EnStatus clsUser::AddToFile()
{
	fstream File;
	File.open(DataFilePath, ios::app | ios::out);

	if (!File.is_open())
		return FailedWriteToFile;

	File << UserDataToRecord(*this) + '\n';

	File.close();

	return Success;
}

clsUser::EnStatus clsUser::Delete()
{
	vector<clsUser> vUsers;
	if (ReadFromFile(vUsers) == FileNotFound)
		return FileNotFound;

	vector<clsUser>::iterator UserIterator;

	for (UserIterator = vUsers.begin(); UserIterator < vUsers.end(); UserIterator++)
	{
		if (UserIterator->UserName == UserName)
		{
			vUsers.erase(UserIterator);
			return WriteToFile(vUsers);
		}
	}

	return UserNotFound;
}

clsUser::EnStatus clsUser::Update()
{
	vector<clsUser> vUsers;

	if (ReadFromFile(vUsers) == FileNotFound)
		return FileNotFound;

	if (UpdateUserVector(vUsers) == Success)
		return WriteToFile(vUsers);

	return UserNotFound;
}

bool clsUser::HasPermission(EnPermissions Permission)
{
	return Permission& this->Permissions;
}

clsUser::EnStatus clsUser::SaveLog()
{
	fstream File;
	File.open(LogFilePath, ios::out | ios::app);

	if (!File.is_open())
		return FailedWriteToFile;

	File << GetLogRecord();

	File.close();

	return Success;
}

//------------------------------
// Private Methods
//------------------------------

string clsUser::UserDataToRecord(clsUser User, string Separator)
{
	string Record;

	Record += User.GetFirstName() + Separator;
	Record += User.GetLastName() + Separator;
	Record += User.GetEmail() + Separator;
	Record += User.GetPhone() + Separator;

	Record += User.GetUserName() + Separator;
	Record += User.GetPassword() + Separator;
	Record += to_string(User.GetPermissions());

	return Record;
}

clsUser::EnStatus clsUser::WriteToFile(vector<clsUser> vUsers)
{
	fstream File;

	File.open(DataFilePath, ios::out);

	if (!File.is_open())
		return FailedWriteToFile;

	for (clsUser User : vUsers)
		File << UserDataToRecord(User) + '\n';

	File.close();

	return Success;
}

clsUser::EnStatus clsUser::UpdateUserVector(vector<clsUser>& vUsers)
{
	for (clsUser& User : vUsers)
	{
		if (User.UserName == UserName)
		{
			User = *this;
			return Success;
		}
	}

	return UserNotFound;
}

string clsUser::GetLogRecord(string Separator)
{
	string CurrentDate = clsDate::FormatDate(clsDate::GetCurrentDate());
	string CurrentTime = clsDate::FormatDate(clsDate::GetCurrentTime(), "dd:mm:yyyy");

	string LogMessage;

	LogMessage += CurrentDate + " - " + CurrentTime + Separator;
	LogMessage += UserName + Separator;
	LogMessage += Password + Separator;
	LogMessage += to_string(Permissions) + '\n';

	return LogMessage;
}

//------------------------------
// Public Static Methods
//------------------------------

clsUser::EnStatus clsUser::ReadFromFile(vector<clsUser>& vUsers)
{
	fstream File;
	File.open(DataFilePath, ios::in);

	if (!File.is_open())
		return FileNotFound;

	string Line;
	while (getline(File, Line))
		vUsers.push_back(RecordToUserObject(Line));

	File.close();
	return FileExist;
}

void clsUser::SetDataFilePath(const string& FilePath) { DataFilePath = FilePath; }

clsUser::EnStatus clsUser::GetFileStatus()
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

clsUser::EnStatus clsUser::GetLog(vector<StLog>& vLog, string Separator)
{
	fstream File;
	File.open(LogFilePath, ios::in);

	if (!File.is_open())
		return FileNotFound;

	string Line;

	while (getline(File, Line))
		vLog.push_back(LogRecordToStruct(Line));

	File.close();

	return FileExist;
}

//------------------------------
// Private Static Methods
//------------------------------

clsUser clsUser::FindUser(const string& UserName)
{
	vector<clsUser> vUsers;
	ReadFromFile(vUsers);

	for (clsUser User : vUsers)
	{
		if (User.UserName == UserName)
		{
			User.UserStatus = UserExist;
			return User;
		}
	}

	return GetEmptyUser(UserName);
}

clsUser clsUser::RecordToUserObject(string Record, string Separator)
{
	clsUser User = GetEmptyUser("");

	vector<string> SparatedString = clsString::Split(Record, Separator);

	User.SetFirstName(SparatedString[0]);
	User.SetLastName(SparatedString[1]);
	User.SetEmail(SparatedString[2]);
	User.SetPhone(SparatedString[3]);

	User.UserName = SparatedString[4];
	User.Password = SparatedString[5];
	User.Permissions = stof(SparatedString[6]);

	User.UserStatus = UserExist;

	return User;
}

clsUser clsUser::GetEmptyUser(const string& UserName)
{
	clsUser EmptyUser = clsUser("", "", "", "", UserName, "", NULL, UserNotFound);
	return EmptyUser;
}

clsUser::StLog clsUser::LogRecordToStruct(string LogRecord, string Separator)
{
	vector<string> vLog = clsString::Split(LogRecord, Separator);

	return StLog{ vLog[0], vLog[1], vLog[2], stoi(vLog[3]) };
}
