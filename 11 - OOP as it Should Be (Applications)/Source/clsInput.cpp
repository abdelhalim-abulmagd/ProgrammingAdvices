

#include "clsInput.h"

//------------------------------
// Static Public Methods
//------------------------------

clsInput::clsInput() {}

clsInput::~clsInput() {}

string clsInput::ReadString(const string& Message)
{
	string String;
	cout << Message;
	getline(cin >> ws, String);
	
	return String;
}

int clsInput::ReadNumber(const string& Message, EnNumberType Type = Any)
{
	int Number;

	do
	{
		cout << Message;
		cin >> Number;

		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			continue;
		}

	} while (!CheckNumberType(Number, Type));

	return Number;

}

int clsInput::ReadNumber(const string& Message, int From, int To)
{
	int Number;

	do
	{
		Number = ReadNumber(Message, Any);

	} while (!IsInRange(Number, From, To));

	return Number;
}

//------------------------------
// Static Private Methods
//------------------------------

bool clsInput::CheckNumberType(int Number, EnNumberType Type)
{
	switch (Type)
	{

	case Positive:
		return IsPositive(Number);

	case Any:
		return true;
	}
}

bool clsInput::IsPositive(int Number) { return Number > 0 ; }

bool clsInput::IsInRange(int Number, int From, int To) { return Number >= From && Number <= To; }
