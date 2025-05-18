
#include <iostream>
#include <string>

using namespace std;

enum EnGrads { A, B, C, D, E, F};

float ReadGrade(const string & Msg)
{
	float Number;
	cout << Msg ;
	cin >> Number;
	return Number;
}

void Print(const string & text)
{
	cout << text << '\n';
}

bool CheckGradeBetweenTwoNumbers(const float & Grade, const int&  From,const int & To)
{
	return Grade >= From && Grade <= To;
}

EnGrads GetGrade(const float & Grade)
{
	if(CheckGradeBetweenTwoNumbers(Grade, 50, 59))
		return E;

	else if(CheckGradeBetweenTwoNumbers(Grade, 60, 69))
		return D;

	else if(CheckGradeBetweenTwoNumbers(Grade, 70, 79))
		return C;

	else if(CheckGradeBetweenTwoNumbers(Grade, 80, 89))
		return B;

	else if(CheckGradeBetweenTwoNumbers(Grade, 90, 100))
		return A;

	else
		return F;
}

string GetResult(const EnGrads& Grade)
{
	switch (Grade)
	{
	case A:
		return "A";
	case B:
		return "B";
	case C:
		return "C";
	case D:
		return "D";
	case E:
		return "E";
	case F:
		return "F";
	}
}

int main()
{
	int Grade = ReadGrade("Enter Grade : ");

	Print(GetResult(GetGrade(Grade)));
}
