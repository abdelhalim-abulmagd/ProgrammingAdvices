#pragma once

#include <vector>
#include <string>

using namespace std;


class clsString
{
public:
	clsString(const string& Text);

	virtual ~clsString();

	string GetString();

	void SetString(string String);

	vector<string> Split(string Separator = " ");
	static vector<string> Split(string StringToSplit, string Separator = " ");

	static string NumberToText(long long int Number);

	static string Replace(string WordToReplace, string ReplaceTo, string String, bool MatchCase = true);
	void Replace(string WordToReplace, string ReplaceTo, bool MatchCase = true);

	static string ToLower(string String);
	void ToLower();

private:
	string String;
};