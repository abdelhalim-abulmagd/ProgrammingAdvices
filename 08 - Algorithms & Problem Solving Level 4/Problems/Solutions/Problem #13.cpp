
#include <iostream>

using namespace std;


struct StDate
{
	short Day;
	short Month;
	short Year;
};


bool IsDate1LessThanDate2(StDate Date1, StDate Date2)
{
	if (Date1.Year < Date2.Year)
		return true;

	else if (Date1.Year == Date2.Year)
		if (Date1.Month < Date2.Month)
			return true;

		else if (Date1.Month == Date2.Month)
			return (Date1.Day < Date2.Day);

	return false;
}

int main()
{
	StDate Date;
	StDate Date2;

	Date.Day = 12;
	Date.Month = 2;
	Date.Year = 2022;

	Date2.Day = 12;
	Date2.Month = 3;
	Date2.Year = 2022;

	cout <<IsDate1LessThanDate2(Date, Date2);

}
