
#include <iostream>
#include <string>

using namespace std;

string readName()
{
	string name;
	getline(cin, name);
	return name;
}

void print(const string &text)
{
	cout << text << '\n';
}

int main()
{
	print(readName());
}
