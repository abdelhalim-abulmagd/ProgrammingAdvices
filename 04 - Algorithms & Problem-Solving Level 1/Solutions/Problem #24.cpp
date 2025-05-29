
#include <iostream>
#include <string>

using namespace std;

short readAge()
{
	short Age;
	cout << "Age : ";
	cin >> Age;
	return Age;
}

bool IsValidAge(const short& Age,const short& From = 18, const short& To = 45)
{
	return Age >= From && Age <= To;
}

void print()
{
	if(IsValidAge(readAge()))
		cout << "Valid" << '\n';
	else
		cout << "UnValid" << '\n';
}

int main()
{
	print();
}
