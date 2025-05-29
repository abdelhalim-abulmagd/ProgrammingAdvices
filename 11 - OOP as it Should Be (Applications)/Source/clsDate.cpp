#include "clsDate.h"

#include "clsString.h"
#include <ctime>


//----------------------------
// Public Methods
//----------------------------

clsDate::clsDate() { *this = GetCurrentDate(); }

clsDate::clsDate(const string& Date) { *this = StringToDate(Date); }

clsDate::clsDate(short Day, short Month, short Year) : Day(Day), Month(Month), Year(Year) {}

clsDate::~clsDate() {}

string clsDate::FormatDate(string Format) { return FormatDate(*this, Format); }


//----------------------------
// Public Static Methods
//----------------------------

string clsDate::FormatDate(clsDate Date, string Format)
{
	Format = clsString::Replace("dd", to_string(Date.Day), Format);
	Format = clsString::Replace("mm", to_string(Date.Month), Format);
	Format = clsString::Replace("yyyy", to_string(Date.Year), Format);

	return Format;
}

clsDate clsDate::GetCurrentDate()
{
	time_t TimeNow = time(0);
	tm* LocalTime = localtime(&TimeNow);

	short Day = LocalTime->tm_mday;
	short Month = LocalTime->tm_mon + 1;
	short Year = LocalTime->tm_year + 1900;

	return clsDate(Day, Month, Year);
}


clsDate clsDate::StringToDate(string DateString, string Separator)
{
	vector<string> SparatedString = clsString::Split(DateString, Separator);

	short Day = stoi(SparatedString[0]);
	short Month = stoi(SparatedString[1]);
	short Year = stoi(SparatedString[2]);

	return clsDate(Day, Month, Year);
}

clsDate clsDate::GetCurrentTime()
{
	time_t Time = time(0);
	tm* LocalTime = localtime(&Time);

	short Hour = LocalTime->tm_hour;
	short Minutes = LocalTime->tm_min;
	short Seconds = LocalTime->tm_sec;

	return clsDate(Hour, Minutes, Seconds);
}
