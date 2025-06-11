#pragma once
#include "clsClint.h"

#include "clsPerson.h"
#include <vector>

using namespace std;

class clsUser : public clsPerson
{

public:

	struct StLog
	{
		string Date;
		string UserName;
		string Password;
		int Permissions;
	};

	struct StTransferLog
	{
		string Date;

		string User;
		float Amount;

		string SourceAccount;
		float SourceBalanceBefore;
		float SourceBalanceAfter;

		string TargetAccount;
		float TargetBalanceBefore;
		float TargetBalanceAfter;
	};

	enum EnStatus { FailedWriteToFile, UserNotFound, FileNotFound, FileExist, UserExist, Success};

	enum EnPermissions {
		AllPermissios = -1, ShowClintsListScreen = 1, AddNewClintScreen = 2, DeleteClintScreen = 4, UpdateClintScreen = 8,
		TransactionScreen = 16, ManageUsersScreen = 32, clsLogScreen = 64
	};

	clsUser(const string& UserName);

	clsUser(const string& UserName, const string& Password);

	clsUser(const string& FirstName, const string& LastName, const string& Phone, const string& Email,
		const string& UserName, const string& Password, const int& Permissions, EnStatus UserStatus);

	virtual ~clsUser();

	EnStatus GetUserStatus();

	string GetUserName();

	string GetPassword();
	void SetPassword(const string& Password);

	int GetPermissions();
	void SetPermissions(const int& Permissions);

	EnStatus AddToFile();

	EnStatus Delete();

	EnStatus Update();

	EnStatus SaveLog();

	EnStatus SaveTransferLog(clsClint SourceClint, clsClint TargetClint, float TransferAmount);

	bool HasPermission(EnPermissions Choice);

	static void SetDataFilePath(const string& FilePath);

	static EnStatus ReadFromFile(vector<clsUser>& vUsers);

	static EnStatus GetFileStatus();

	static  EnStatus GetLog(vector<StLog>& vLog, string Separator = "#//#");

	static  EnStatus GetTransferLog(vector<StTransferLog>& vTransferLog, string Separator = "#//#");

private:



	EnStatus UserStatus;

	string UserName;
	string Password;
	int Permissions;

	string UserDataToRecord(clsUser User, string Separator = "#//#");

	EnStatus WriteToFile(vector<clsUser> vUsers);

	clsUser::EnStatus UpdateUserVector(vector<clsUser>& vUsers);

	string GetLogRecord(string Separator = "#//#");

	string GetTransferLogRecord(clsClint SourceClint, clsClint TargetClint, float TransferAmount, string Separator = "#//#");

	static clsUser FindUser(const string& UserName);

	static clsUser RecordToUserObject(string String, string Separator = "#//#");

	static clsUser GetEmptyUser(const string& UserName);

	static StLog LogRecordToStruct(string LogRecord, string Separator = "#//#");

	static StTransferLog TransferLogRecordToStruct(string LogRecord, string Separator = "#//#");

};