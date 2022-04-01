#include "CommandParser.h"

// public
InputParameter CommandParser::ConvertParameter(const string& inputString)
{
	InputParameter inputParameter;
	vector<string> parsedStrings = _Parsing(inputString, ",");

	Column column = _ConvertColumn(parsedStrings.at(COLUMN_OFFSET));

	inputParameter.command = _ConvertCommand(parsedStrings.at(CMD_OFFSET));
	inputParameter.option1 = _ConvertOption1(parsedStrings.at(OPTION1_OFFSET));
	inputParameter.option2 = _ConvertOption2(parsedStrings.at(OPTION2_OFFSET), column);
	inputParameter.column = column;

	if (inputParameter.command == Command::Command_Add)
	{
		inputParameter.inputEmployee.SetData(stoi(parsedStrings.at(ADDCMD_EMPLOYEENUM_OFFSET)),
											 _ConvertName(parsedStrings.at(ADDCMD_NAME_OFFSET), inputParameter.option2),
											 _ConvertCareerLevel(parsedStrings.at(ADDCMD_CL_OFFSET)),
											 _ConvertPhoneNum(parsedStrings.at(ADDCMD_PHONENUM_OFFSET)),
											 _ConvertBirthDay(parsedStrings.at(ADDCMD_BIRTHDAY_OFFSET)),
											 _ConvertCerti(parsedStrings.at(ADDCMD_CERTI_OFFSET)));
	}
	else if (inputParameter.command == Command::Command_Mod)
	{
		_SetValue(parsedStrings.at(VALUE_OFFSET), column, inputParameter.option2, inputParameter.inputEmployee);
		_SetValue(parsedStrings.at(MODCMD_DEST_VALUE_OFFSET), _ConvertColumn(parsedStrings.at(MODCMD_DEST_COLUMN_OFFSET)), Option2::Option2_None, inputParameter.inputDestEmployee);
	}
	else
	{
		_SetValue(parsedStrings.at(VALUE_OFFSET), column, inputParameter.option2, inputParameter.inputEmployee);
	}

	return inputParameter;
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

void CommandParser::_SetValue(const string& inputString, const Column& column, const Option2& option2, Employee& employee)
{
	if (column == Column::Column_employeeNum)
	{
		employee.SetData(stoi(inputString), {"", ""} , CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi::Certi_None);
	}
	else if (column == Column::Column_Name)
	{
		employee.SetData(0, _ConvertName(inputString, option2), CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), Certi::Certi_None);
	}
	else if (column == Column::Column_CareerLevel)
	{
		employee.SetData(0, {"", ""}, _ConvertCareerLevel(inputString), PhoneNum(0, 0), BirthDay(0, 0, 0), Certi::Certi_None);
	}
	else if (column == Column::Column_PhoneNum)
	{
		employee.SetData(0, {"", ""}, CareerLevel::CareerLevel_None, _ConvertPhoneNum(inputString), BirthDay(0, 0, 0), Certi::Certi_None);
	}
	else if (column == Column::Column_BirthDay)
	{
		if (option2 == Option2::Option2_BirthDay_y)
		{
			employee.SetData(0, {"", ""}, CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(stoi(inputString.substr(0, 4)), 0, 0), Certi::Certi_None);
		}
		else if (option2 == Option2::Option2_BirthDay_m)
		{
			employee.SetData(0, {"", ""}, CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, stoi(inputString.substr(0, 2)), 0), Certi::Certi_None);
		}
		else if (option2 == Option2::Option2_BirthDay_d)
		{
			employee.SetData(0, {"", ""}, CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, stoi(inputString.substr(0, 2))), Certi::Certi_None);
		}
		else
		{
			employee.SetData(0, {"", ""}, CareerLevel::CareerLevel_None, PhoneNum(0, 0), _ConvertBirthDay(inputString), Certi::Certi_None);
		}
	}
	else if (column == Column::Column_Certi)
	{
		employee.SetData(0, {"", ""}, CareerLevel::CareerLevel_None, PhoneNum(0, 0), BirthDay(0, 0, 0), _ConvertCerti(inputString));
	}
}

Command CommandParser::_ConvertCommand(const string& inputString)
{
	if (inputString == "ADD")
	{
		return Command::Command_Add;
	}
	else if (inputString == "SCH")
	{
		return Command::Command_Sch;
	}
	else if (inputString == "DEL")
	{
		return Command::Command_Del;
	}
	else if (inputString == "MOD")
	{
		return Command::Command_Mod;
	}
	else 
	{
		return Command::Command_None;
	}
}

Name CommandParser::_ConvertName(const string& inputNameString, const Option2& option2)
{
	vector<string> parsedPhoneNum = _Parsing(inputNameString, " ");

	if (option2 == Option2::Option2_Name_f)
	{
		return Name(parsedPhoneNum.at(0), "");
	}
	else if (option2 == Option2::Option2_Name_l)
	{
		return Name("", parsedPhoneNum.at(0));
	}
	else
	{
		// LastNameÀÌ ¼º
		// Input : "È« ±æµ¿"
		return Name(parsedPhoneNum.at(1), parsedPhoneNum.at(0));
	}
}

CareerLevel CommandParser::_ConvertCareerLevel(const string& inputClString)
{
	if (inputClString == "CL1")
	{
		return CareerLevel::CareerLevel_1;
	}
	else if (inputClString == "CL2")
	{
		return CareerLevel::CareerLevel_2;
	}
	else if (inputClString == "CL3")
	{
		return CareerLevel::CareerLevel_3;
	}
	else if (inputClString == "CL4")
	{
		return CareerLevel::CareerLevel_4;
	}
	else
	{
		return CareerLevel::CareerLevel_None;
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
		return Certi::Certi_ADV;
	}
	else if (inputCertiString == "PRO")
	{
		return Certi::Certi_PRO;
	}
	else if (inputCertiString == "EX")
	{
		return Certi::Certi_EX;
	}
	else
	{
		return Certi::Certi_None;
	}
}

Option1 CommandParser::_ConvertOption1(const string& inputString)
{
	if (inputString == "-p")
	{
		return Option1::Option1_p;
	}
	else
	{
		return Option1::Option1_None;
	}
}

Option2 CommandParser::_ConvertOption2(const string& inputString, const Column& column)
{
	if (inputString == " ")
	{
		return Option2::Option2_None;
	}

	if (column == Column::Column_Name)
	{
		if (inputString == "-f")
		{
			return Option2::Option2_Name_f;
		}
		else if (inputString == "-l")
		{
			return Option2::Option2_Name_l;
		}
	}
	else if (column == Column::Column_PhoneNum)
	{
		if (inputString == "-m")
		{
			return Option2::Option2_PhoneNum_m;
		}
		else if (inputString == "-l")
		{
			return Option2::Option2_PhoneNum_l;
		}
	}
	else if (column == Column::Column_BirthDay)
	{
		if (inputString == "-y")
		{
			return Option2::Option2_BirthDay_y;
		}
		else if (inputString == "-m")
		{
			return Option2::Option2_BirthDay_m;
		}
		else if (inputString == "-d")
		{
			return Option2::Option2_BirthDay_d;
		}
	}

	cout << "=================== Error Test=====================" << endl;
	return Option2::Option2_None;
}

Column CommandParser::_ConvertColumn(const string& inputString)
{
	if (inputString == "employeeNum")
	{
		return Column::Column_employeeNum;
	}
	else if (inputString == "name")
	{
		return Column::Column_Name;
	}
	else if (inputString == "cl")
	{
		return Column::Column_CareerLevel;
	}
	else if (inputString == "phoneNum")
	{
		return Column::Column_PhoneNum;
	}
	else if (inputString == "birthday")
	{
		return Column::Column_BirthDay;
	}
	else if (inputString == "certi")
	{
		return Column::Column_Certi;
	}
	else
	{
		return Column::Column_None;
	}
}
