#pragma once
#include <string>
using namespace std;

enum CareerLevel
{
	CareerLevel_1 = 0,
	CareerLevel_2,
	CareerLevel_3,
	CareerLevel_4,
};

enum Certi
{
	Certi_ADV = 0,
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
	Employee(const int& employeeNum, const string& name, const CareerLevel& cl, const PhoneNum& phoneNum, const BirthDay& birthDay, const Certi& certi) :
		_employeeNum(employeeNum),
		_name(name),
		_cl(cl),
		_phoneNum(phoneNum),
		_birthDay(birthDay),
		_certi(certi)
	{}

	int GetEmployeeNum()
	{
		return _employeeNum;
	}
	string GetName()
	{
		return _name;
	}
	CareerLevel GetCl()
	{
		return _cl;
	}
	PhoneNum GetPhoneNum()
	{
		return _phoneNum;
	}
	BirthDay GetBirthDay()
	{
		return _birthDay;
	}
	Certi GetCerti()
	{
		return _certi;
	}
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