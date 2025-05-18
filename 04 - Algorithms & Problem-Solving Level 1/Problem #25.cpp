
#include <iostream>
#include <string>

using namespace std;


bool IsValidAge(const short& Age,const short& From = 18, const short& To = 45)
{
	return Age >= From && Age <= To;
}


short readAge()
{
	short Age;

	do
	{
		cout << "Age : ";
		cin >> Age;

	} while (!IsValidAge(Age));

	return Age;

}

void print(const string & text)
{
	cout << text << '\n';
}

int main()
{
	print(to_string(readAge()));
}
