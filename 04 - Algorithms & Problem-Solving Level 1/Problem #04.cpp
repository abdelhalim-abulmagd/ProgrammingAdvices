
#include <iostream>
#include <string>

using namespace std;

int readAge()
{
	int number;
	cout << "Age : ";
	cin >> number;
	return number;
}
bool readDiverLicense()
{
	bool hasLicense;
	cout << "Has Driver License ? [0 or 1] : ";
	cin >> hasLicense;
	return hasLicense;
}

bool isAccsepted(int age, bool hasDriverLicense)
{
	return age > 21 && hasDriverLicense;
}


string result(int age, bool hasDriverLicense)
{
	if (isAccsepted(age,  hasDriverLicense))
	{
		return "Hierd";
	}
	return "Rejucted";
}

void print(const string &text)
{
	cout << text << '\n';
}


int main()
{
	
	print(result(readAge(), readDiverLicense()));
}
