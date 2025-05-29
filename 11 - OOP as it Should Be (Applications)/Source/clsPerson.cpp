#include "clsPerson.h"

//------------------------------
// Public Methods
//------------------------------

clsPerson::clsPerson(const string& FirstName, const string& LastName, const string& Phone, const string& Email)
	: FirstName(FirstName), LastName(LastName), Phone(Phone), Email(Email) { }

clsPerson::~clsPerson() { }


string clsPerson::GetFirstName() { return FirstName; }
void clsPerson::SetFirstName(const string& FirstName) { this->FirstName = FirstName; }

string clsPerson::GetLastName() { return LastName; }
void clsPerson::SetLastName(const string& LastName) { this->LastName = LastName; }

string clsPerson::GetEmail() { return Email; }
void clsPerson::SetEmail(const string& Email) { this->Email = Email; }

string clsPerson::GetPhone() { return Phone; }
void clsPerson::SetPhone(const string& Phone) { this->Phone = Phone; }

string clsPerson::GetFullName() { return FirstName + " " + LastName; }
