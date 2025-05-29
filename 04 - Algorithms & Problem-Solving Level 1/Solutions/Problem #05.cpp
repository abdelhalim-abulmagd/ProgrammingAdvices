
#include <iostream>
#include <string>

using namespace std;

struct stInfo
{
	int age;
	bool hasDriverLicense;
	bool hasRecomendation;
};


stInfo readInfo()
{
	stInfo info;
	
	cout << "Age : ";
	cin >> info.age;

	cout << "Has Driver License ? [0 or 1] : ";
	cin >> info.hasDriverLicense;
	
	cout << "Has Recomendation ? [0 or 1] : ";
	cin >> info.hasRecomendation;

	return info;
}

bool isAccsepted(const stInfo& info)
{
	return info.hasRecomendation || (info.age > 21 && info.hasDriverLicense);
}


string result(const stInfo& info)
{
	if (isAccsepted(info))
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
	
	print(result(readInfo()));
}
