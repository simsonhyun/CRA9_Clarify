#pragma once
#include <string>
#include <vector>
#include "Employee.h"
using namespace std;

enum class CommandType
{
	Command_Add = 0,
	Command_Sch,
	Command_Del,
	Command_Mod,
	Command_None,
};

enum class Option1
{
	Option1_None = 0,
	Option1_p,		// print
};

enum class Option2
{
	Option2_None = 0,
	Option2_Name_f,		// first name
	Option2_Name_l,		// last name
	Option2_PhoneNum_m,	// middle Number
	Option2_PhoneNum_l,	// last Number
	Option2_BirthDay_y,	// year
	Option2_BirthDay_m,	// month
	Option2_BirthDay_d,	// day
};

enum class Column
{
	Column_employeeNum = 0,
	Column_Name,
	Column_CareerLevel,
	Column_PhoneNum,
	Column_BirthDay,
	Column_Certi,
	Column_None,
};

typedef struct InputParameter
{
	CommandType command;
	Option1 option1;
	Option2 option2;
	Column column;
	Column destColumn;
	Employee inputEmployee;
	Employee inputDestEmployee;
} InputParameter;

typedef struct OutputParameter
{
	int resultCount;
	vector<Employee> resultVector;
} OutputParameter;