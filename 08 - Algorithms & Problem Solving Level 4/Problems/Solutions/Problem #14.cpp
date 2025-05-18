
#include <iostream>

using namespace std;


struct StDate
{
	short Day;
	short Month;
	short Year;
};


bool IsDate1EqualDate2(StDate Date1, StDate Date2)
{
	return (Date1.Year == Date2.Year) && (Date1.Month == Date2.Month) && (Date1.Day == Date2.Day);
}

int main()
{
	StDate Date;
	StDate Date2;

	Date.Day = 12;
	Date.Month = 2;
	Date.Year = 2022;

	Date2.Day = 12;
	Date2.Month = 2;
	Date2.Year = 2022;

	cout << IsDate1EqualDate2(Date, Date2);

}
