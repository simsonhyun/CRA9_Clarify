#pragma once
#include <string>
using namespace std;

enum Option1
{
	Option1_p,	// print
};

enum Option2
{
	Option2_Name_f,		// first name
	Option2_Name_l,		// last name
	Option2_PhoneNum_m,	// middle Number
	Option2_PhoneNum_l,	// last Number
	Option2_BirthDay_y,	// year
	Option2_BirthDay_m,	// month
	Option2_BirthDay_d,	// day
};

enum Column
{
	Column_employeeNum,
	Column_Name,
	Column_CareerLevel,
	Column_PhoneNum,
	Column_BirthDay,
	Column_Certi,
};

enum CareerLevel
{
	CareerLevel_1,
	CareerLevel_2,
	CareerLevel_3,
	CareerLevel_4,
};

enum Certi
{
	Certi_ADV,
	Certi_PRO,
	Certi_EX,
};

typedef struct PhoneNum
{
	int middleNum;
	int lastNum;

	PhoneNum& operator=(const PhoneNum& r) 
	{
		if (this == &r)
		{
			return *this;
		}

		middleNum = r.middleNum;
		lastNum = r.lastNum;
		return *this;
	}
};

typedef struct BirthDay
{
	int year;
	int month;
	int day;

	BirthDay& operator=(const BirthDay& r)
	{
		if (this == &r)
		{
			return *this;
		}

		year = r.year;
		month = r.month;
		day = r.day;
		return *this;
	}
};

typedef struct InputParameter
{
	Option1 option1;
	Option2 option2;
	Column column;
	string value;
	PhoneNum phoneNum;	// 사용하지 않으면 0으로 채움;
};