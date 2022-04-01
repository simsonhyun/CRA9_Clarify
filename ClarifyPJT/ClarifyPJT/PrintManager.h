#pragma once
#include <vector>
#include "Employee.h"
using namespace std;

class PrintManager
{
private:
	string _GetCommandString(const Command& command)
	{
		if (command == Command::Command_Add)
		{
			return "ADD,";
		}
		else if (command == Command::Command_Sch)
		{
			return "SCH,";
		}
		else if (command == Command::Command_Del)
		{
			return "DEL,";
		}
		else if (command == Command::Command_Mod)
		{
			return "MOD,";
		}
		else
		{
			return "";
		}
	}

	string _ConvertEmployeeNum(const int& employeeNum) const
	{
		char buf[10];
		sprintf(buf, "%08d", employeeNum);
		return string(buf) + ",";
	}

	string _ConvertName(const Name& name) const
	{
		return string(name._lastName) + " " + string(name._firstName) + ",";
	}

	string _ConvertCl(const CareerLevel& cl) const
	{
		if (cl == CareerLevel::CareerLevel_1)
		{
			return "CL1,";
		}
		else if (cl == CareerLevel::CareerLevel_2)
		{
			return "CL2,";
		}
		else if (cl == CareerLevel::CareerLevel_3)
		{
			return "CL3,";
		}
		else if (cl == CareerLevel::CareerLevel_4)
		{
			return "CL4,";
		}
		else
		{
			// Error...
			return " ,";
		}
	}

	string _ConvertPhoneNum(const PhoneNum& phoneNum) const
	{
		return "010-" + to_string(phoneNum._middleNum) + "-" + to_string(phoneNum._lastNum) + ",";
	}

	string _ConvertBirthDay(const BirthDay& birthDay) const
	{
		string retString;
		retString.append(to_string(birthDay._year));
		
		if (birthDay._month < 10)
		{
			retString.append("0");
		}
		retString.append(to_string(birthDay._month));

		if (birthDay._day < 10)
		{
			retString.append("0");
		}
		retString.append(to_string(birthDay._day));

		return retString + ",";
	}

	string _ConvertCerti(const Certi& certi) const
	{
		string outString;

		if (certi == Certi::Certi_ADV)
		{
			outString = "ADV";
		}
		else if (certi == Certi::Certi_PRO)
		{
			outString = "ADV";
		}
		else if (certi == Certi::Certi_EX)
		{
			outString = "ADV";
		}
		outString += 0xA; // Next Line

		return outString;
	}

public:
	string Print(const Command& command, const vector< Employee>& commandResultEmployees)
	{
		string retString;

		if (commandResultEmployees.size() == 0)
		{
			retString = _GetCommandString(command);
			retString.append("NONE");
			retString += 0xA; // Next Line

			return retString;
		}

		for (auto employee : commandResultEmployees)
		{
			retString.append(_GetCommandString(command));
			retString.append(_ConvertEmployeeNum(employee.GetEmployeeNum()));
			retString.append(_ConvertName(employee.GetName()));
			retString.append(_ConvertCl(employee.GetCl()));
			retString.append(_ConvertPhoneNum(employee.GetPhoneNum()));
			retString.append(_ConvertBirthDay(employee.GetBirthDay()));
			retString.append(_ConvertCerti(employee.GetCerti()));
		}

		return retString;
	}

	void PrintNotOption(int commandResult) const
	{

	}

private:
public:

};