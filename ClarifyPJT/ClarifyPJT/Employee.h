#pragma once
#include <string>
using namespace std;

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

class Employee
{
public:
private:
	

public:
private:
	int _employeeNum;
	string _name;
	CareerLevel _cl;
	PhoneNum _phoneNum;
	BirthDay _birthDay;
	Certi _certi;

};