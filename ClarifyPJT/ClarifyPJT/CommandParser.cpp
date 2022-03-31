#include "CommandParser.h"

// public
InputParameter CommandParser::ConvertParameter(const string&& inputString)
{
	InputParameter ret;
	vector<string> parsedStrings = _Parsing(inputString, ",");

	Column column = _ConvertColumn(parsedStrings.at(COLUMN_OFFSET));

	ret.option1 = _ConvertOption1(parsedStrings.at(OPTION1_OFFSET));
	ret.option2 = _ConvertOption2(parsedStrings.at(OPTION2_OFFSET), column);
	ret.column = column;

	if (parsedStrings.at(CMD_OFFSET) == "ADD")
	{
		ret.inputEmployee.SetData(stoi(parsedStrings.at(ADDCMD_EMPLOYEENUM_OFFSET)),
			parsedStrings.at(ADDCMD_NAME_OFFSET),
			_ConvertCareerLevel(parsedStrings.at(ADDCMD_CL_OFFSET)),
			_ConvertPhoneNum(parsedStrings.at(ADDCMD_PHONENUM_OFFSET)),
			_ConvertBirthDay(parsedStrings.at(ADDCMD_BIRTHDAY_OFFSET)),
			_ConvertCerti(parsedStrings.at(ADDCMD_CERTI_OFFSET)));
	}
	else
	{
		_SetValue(parsedStrings.at(VALUE_OFFSET), column, ret);
	}

	return ret;
}

// private
vector<string> CommandParser::_Parsing(const string& inputString, const string& delimiter) const
{
	vector<string> values;

	string::size_type Fpos = inputString.find_first_not_of(delimiter, 0);
	string::size_type Lpos = inputString.find_first_of(delimiter, Fpos);

	while (string::npos != Fpos || string::npos != Lpos)
	{
		values.push_back(inputString.substr(Fpos, Lpos - Fpos));
		Fpos = inputString.find_first_not_of(delimiter, Lpos);
		Lpos = inputString.find_first_of(delimiter, Fpos);
	}

	return values;
}

CareerLevel CommandParser::_ConvertCareerLevel(const string& inputClString)
{
	if (inputClString == "CL1")
	{
		return CareerLevel_1;
	}
	else if (inputClString == "CL2")
	{
		return CareerLevel_2;
	}
	else if (inputClString == "CL3")
	{
		return CareerLevel_3;
	}
	else if (inputClString == "CL4")
	{
		return CareerLevel_4;
	}
}

PhoneNum CommandParser::_ConvertPhoneNum(const string& inputPhoneString)
{
	static const int MIDDLE_OFFSET = 1;
	static const int LAST_OFFSET = 2;

	vector<string> parsedPhoneNum = _Parsing(inputPhoneString, "-");
	return PhoneNum(stoi(parsedPhoneNum.at(MIDDLE_OFFSET)), stoi(parsedPhoneNum.at(LAST_OFFSET)));
}

BirthDay CommandParser::_ConvertBirthDay(const string& inputBirthDayString)
{
	return BirthDay(stoi(inputBirthDayString.substr(0, 4)), stoi(inputBirthDayString.substr(4, 2)), stoi(inputBirthDayString.substr(6, 2)));
}

Certi CommandParser::_ConvertCerti(const string& inputCertiString)
{
	if (inputCertiString == "ADV")
	{
		return Certi_ADV;
	}
	else if (inputCertiString == "PRO")
	{
		return Certi_PRO;
	}
	else if (inputCertiString == "EX")
	{
		return Certi_EX;
	}
}

Option1 CommandParser::_ConvertOption1(const string& inputString)
{
	if (inputString == "-p")
	{
		return Option1_p;
	}
	else
	{
		return Option1_None;
	}
}

Option2 CommandParser::_ConvertOption2(const string& inputString, const Column& column)
{
	if (inputString == " ")
	{
		return Option2_None;
	}

	if (column == Column_Name)
	{
		if (inputString == "-f")
		{
			return Option2_Name_f;
		}
		else if (inputString == "-l")
		{
			return Option2_Name_l;
		}
	}
	else if (column == Column_PhoneNum)
	{
		if (inputString == "-m")
		{
			return Option2_PhoneNum_m;
		}
		else if (inputString == "-l")
		{
			return Option2_PhoneNum_l;
		}
	}
	else if (column == Column_BirthDay)
	{
		if (inputString == "-y")
		{
			return Option2_BirthDay_y;
		}
		else if (inputString == "-m")
		{
			return Option2_BirthDay_m;
		}
		else if (inputString == "-d")
		{
			return Option2_BirthDay_d;
		}
	}

	cout << "=================== Error Test=====================" << endl;
	return Option2_None;
}

Column CommandParser::_ConvertColumn(const string& inputString)
{
	if (inputString == "employeeNum")
	{
		return Column_employeeNum;
	}
	else if (inputString == "name")
	{
		return Column_Name;
	}
	else if (inputString == "cl")
	{
		return Column_CareerLevel;
	}
	else if (inputString == "phoneNum")
	{
		return Column_PhoneNum;
	}
	else if (inputString == "birthday")
	{
		return Column_BirthDay;
	}
	else if (inputString == "certi")
	{
		return Column_Certi;
	}
	else
	{
		return Column_None;
	}
}

void CommandParser::_SetValue(const string& inputString, const Column& column, InputParameter& inputParameter)
{
	if (column == Column_employeeNum)
	{
		inputParameter.inputEmployee.SetData(stoi(inputString), " ", CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi_None);
	}
	else if (column == Column_Name)
	{
		inputParameter.inputEmployee.SetData(0, inputString, CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi_None);
	}
	else if (column == Column_CareerLevel)
	{
		inputParameter.inputEmployee.SetData(0, " ", _ConvertCareerLevel(inputString), PhoneNum(0, 0), BirthDay(0, 0, 0), Certi_None);
	}
	else if (column == Column_PhoneNum)
	{
		inputParameter.inputEmployee.SetData(0, " ", CareerLevel_None, _ConvertPhoneNum(inputString), BirthDay(0, 0, 0), Certi_None);
	}
	else if (column == Column_BirthDay)
	{
		if (inputParameter.option2 == Option2_BirthDay_y)
		{
			inputParameter.inputEmployee.SetData(0, " ", CareerLevel_None, PhoneNum(0, 0), BirthDay(stoi(inputString.substr(0, 4)), 0, 0), Certi_None);
		}
		else if (inputParameter.option2 == Option2_BirthDay_m)
		{
			inputParameter.inputEmployee.SetData(0, " ", CareerLevel_None, PhoneNum(0, 0), BirthDay(0, stoi(inputString.substr(0, 2)), 0), Certi_None);
		}
		else if (inputParameter.option2 == Option2_BirthDay_d)
		{
			inputParameter.inputEmployee.SetData(0, " ", CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, stoi(inputString.substr(0, 2))), Certi_None);
		}
	}
	else if (column == Column_Certi)
	{
		inputParameter.inputEmployee.SetData(0, " ", CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), _ConvertCerti(inputString));
	}
}