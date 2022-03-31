#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "CommonType.h"
using namespace std;

class CommandParser
{
public:
	static const int CMD_OFFSET = 0;
	static const int OPTION1_OFFSET = 1;
	static const int OPTION2_OFFSET = 2;
	static const int OPTION3_OFFSET = 3;
	static const int COLUMN_OFFSET = 4;
	static const int VALUE_OFFSET = 5;

	static const int ADDCMD_EMPLOYEENUM_OFFSET = 4;
	static const int ADDCMD_NAME_OFFSET = 5;
	static const int ADDCMD_CL_OFFSET = 6;
	static const int ADDCMD_PHONENUM_OFFSET = 7;
	static const int ADDCMD_BIRTHDAY_OFFSET = 8;
	static const int ADDCMD_CERTI_OFFSET = 9;

	InputParameter ConvertParameter(const string&& inputString);

private:
	vector<string> _Parsing(const string& inputString, const string& delimiter) const;
	CareerLevel _ConvertCareerLevel(const string& inputClString);
	PhoneNum _ConvertPhoneNum(const string& inputPhoneString);
	BirthDay _ConvertBirthDay(const string& inputBirthDayString);
	Certi _ConvertCerti(const string& inputCertiString);
	Option1 _ConvertOption1(const string& inputString);
	Option2 _ConvertOption2(const string& inputString, const Column& column);
	Column _ConvertColumn(const string& inputString);
	void _SetValue(const string& inputString, const Column& column, InputParameter& inputParameter);

};