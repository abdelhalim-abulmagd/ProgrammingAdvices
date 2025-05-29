#pragma once

#include <string>
#include <iostream>

using namespace std;


class clsInput
{

public:
	clsInput();
	virtual ~clsInput();

	enum EnNumberType { Positive, Any };

	static string ReadString(const string& Message);

	static int ReadNumber(const string& Message, EnNumberType Type);

	static int ReadNumber(const string& Message, int From, int To);

private:
	

	static bool CheckNumberType(int Number, EnNumberType Type);

	static bool IsPositive(int Number);

	static bool IsInRange(int Number, int From, int To);

};
