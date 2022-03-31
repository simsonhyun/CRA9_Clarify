#pragma once
#include <string>
#include "Employee.h"
using namespace std;

enum Option1
{
	Option1_None = 0,
	Option1_p,		// print
	Option1_null,
};

enum Option2
{
	Option2_None = 0,
	Option2_Name_f,		// first name
	Option2_Name_l,		// last name
	Option2_PhoneNum_m,	// middle Number
	Option2_PhoneNum_l,	// last Number
	Option2_BirthDay_y,	// year
	Option2_BirthDay_m,	// month
	Option2_BirthDay_d,	// day
	Option2_null,
};

enum Column
{
	Column_None = 0,
	Column_employeeNum,
	Column_Name,
	Column_CareerLevel,
	Column_PhoneNum,
	Column_BirthDay,
	Column_Certi,
	Column_null,
};

typedef struct InputParameter
{
	Option1 option1;
	Option2 option2;
	Column column;
	Employee inputEmployee;
};