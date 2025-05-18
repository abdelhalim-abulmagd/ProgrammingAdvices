
#include <iostream>
#include <string>

using namespace std;

enum EnOperations { Plus = '+', Minus = '-', Multiply = '*', Divide = '/'};

struct StCalculatorInfo
{
	float Number1;
	float Number2;
	char Operation;
};


short ReadNumber(const string & Msg)
{
	short Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

char ReadOperation(const string & Msg)
{
	char Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}


StCalculatorInfo ReadCalculatorInfo()
{
	StCalculatorInfo CalculatorInfo;

	CalculatorInfo.Number1 = ReadNumber("Enter Number [1] : ");
	CalculatorInfo.Number2 = ReadNumber("Enter Number [2] : ");
	CalculatorInfo.Operation = ReadOperation("Enter Operation [ + | - | * | /] : ");

	return CalculatorInfo;
}

float Sum(int Num1, int Num2)
{
	return Num1 + Num2;
}
float Subtact(int Num1, int Num2)
{
	return Num1 - Num2;
}
float Multiply(int Num1, int Num2)
{
	return Num1 * Num2;
}
float Divide(int Num1, int Num2)
{
	return Num1 / Num2;
}

float Calculate(StCalculatorInfo &CalculatorInfo)
{
	switch (CalculatorInfo.Operation)
	{
	case EnOperations::Plus:
		return Sum(CalculatorInfo.Number1, CalculatorInfo.Number2);

	case EnOperations::Minus:
		return Subtact(CalculatorInfo.Number1, CalculatorInfo.Number2);

	case EnOperations::Multiply:
		return Multiply(CalculatorInfo.Number1, CalculatorInfo.Number2);

	case EnOperations::Divide:
		return Divide(CalculatorInfo.Number1, CalculatorInfo.Number2);
	}
}

void Print(const string & text)
{
	cout << text << '\n';
}

int main()
{

	Print(to_string(Calculate(ReadCalculatorInfo())));
}
