#pragma once

#include <string>

using namespace std;

class clsPerson
{
public:

	clsPerson(const string& FirstName, const string& LastName, const string& Phone, const string& Email);

	virtual ~clsPerson();

	string GetFirstName();
	void SetFirstName(const string& FirstName);

	string GetLastName();
	void SetLastName(const string& LastName);

	string GetPhone();
	void SetPhone(const string& Phone);

	string GetEmail();
	void SetEmail(const string& Email);

	string GetFullName();

private:

	string FirstName;
	string LastName;
	string Phone;
	string Email;

};