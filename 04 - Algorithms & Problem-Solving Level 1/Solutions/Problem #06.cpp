
#include <iostream>
#include <string>

using namespace std;

struct stPersonInfo
{
	string firstName;
	string lastName;
};


stPersonInfo readPersonInfo()
{
	stPersonInfo personInfo;

	cout << "First Name : ";
	getline(cin, personInfo.firstName);
	
	cout << "Last Name : ";
	getline(cin, personInfo.lastName);
	
	return personInfo;
}

string fullName(const stPersonInfo &personInfo)
{
	return personInfo.firstName + " " + personInfo.lastName;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(fullName(readPersonInfo()));
}
